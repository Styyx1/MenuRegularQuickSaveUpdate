#include "Hooks.h"
#include "Logging.h"

SKSEPluginLoad(const SKSE::LoadInterface* skse)
{
    InitLogging();

    const auto plugin{ SKSE::PluginDeclaration::GetSingleton() };
    const auto name{ plugin->GetName() };
    const auto version{ plugin->GetVersion() };

    logger::info("{} {} is loading...", name, version);

    Init(skse);

    logger::info("{} has finished loading.", name);
    logger::info("");
    QuickSave::SystemQuickSaveHook::Hook();

    return true;
}
