#include "pch.h"
#include "core/logger.h"

void stackWalker::OnOutput(LPCSTR szText) {
	strung text(szText);
	logNow(stackwalker, "{}", text.substr(0, text.size() - 1))
}
void stackWalker::OnLoadModule(LPCSTR img, LPCSTR mod, DWORD64 baseAddr, DWORD size, DWORD result, LPCSTR symType, LPCSTR pdbName, ULONGLONG fileVersion) {
	return;
}
void stackWalker::OnSymInit(LPCSTR szSearchPath, DWORD symOptions, LPCSTR szUserName) {
	return;
}
void stackWalker::OnDbgHelpErr(LPCSTR szFuncName, DWORD gle, DWORD64 addr) {
	return;
}
void stackWalker::OnCallstackEntry(CallstackEntryType eType, CallstackEntry& entry) {
	if (!entry.lineFileName[0]) {
		if (entry.name[0]) {
			logNow(stackwalker, "{} (0x{:X}, {}.dll)", entry.name, uint64_t(entry.offset), entry.moduleName);
		}
		return;
	}
}