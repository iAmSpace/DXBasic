#include "core.h"
#include "hooks/hooks.h"
#include "natives/natives.h"
#include "features/features.h"
#include "renderer/renderer.h"
#include "memory/pointers.h"
#include "fiber/fiber.h"
#include "fiber/manager.h"
#include "fiber/queue.h"
#include "script/script.h"
#include "core/logger.h"
#include "exceptions/exception_handler.h"
#include "config/config.h"
#include "util/util.h"

namespace core {
	namespace dll {
		void attach() {
			g_logger = std::make_unique<logger>();
			exceptions::initExceptionHandler();
			core::createThreadInstance();
		}
		void detach() {
			if (!g_wasDllDetachCalled) {
				core::uninit();
				exceptions::uninitExceptionHandler();
				g_logger.reset();
				g_wasDllDetachCalled = true;
			}
		}
	}
	void init() {
		g_running = true;
		g_config.load();
		g_pointers.scan();
		g_invoker.cache();
		g_renderer = std::make_unique<renderer>();
		g_hooking = std::make_unique<hooking>();

		fibers::manager::g_manager = std::make_unique<fibers::manager::manager>();
		fibers::manager::g_manager->push("scriptFiber", &script::onTick);
		fibers::manager::g_manager->push("utilFiber", &util::onTick);
		fibers::manager::g_manager->push("featuresFiber", &features::onTick);
		fibers::queue::g_queue.createScripts();
		g_hooking->hook();
	}
	void uninit() {
		g_hooking->unhook();
		fibers::manager::g_manager.reset();
		g_invoker.m_cache.clear();
		g_hooking.reset();
		g_renderer.reset();
		g_running = false;
	}
	void createThreadInstance() {
		CreateThread(nullptr, 0, [](void* ptr) -> DWORD {
			core::init();
			while (g_running) {
				if (GetAsyncKeyState(VK_END))
					g_running = false;
				std::this_thread::sleep_for(1ms);
			}
			dll::detach();
			FreeLibraryAndExitThread(g_module, 0);
			return 0;
		}, nullptr, 0, nullptr);
	}
}
