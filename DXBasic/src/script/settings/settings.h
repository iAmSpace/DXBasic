#pragma once
#include "pch/pch.h"
#include "gui/submenu_types/submenu.h"
#include "gui/option_types/regular_option.h"
#include "gui/option_types/submenu_option.h"

namespace script {
	using namespace gui::menu::types;
	using namespace gui::menu::options::types;
	class settings : public submenu {
	public:
		settings();
	public:
		static void call(submenu& sub);
	};
}