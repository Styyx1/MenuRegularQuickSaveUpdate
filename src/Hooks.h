#pragma once

namespace QuickSave
{
    class SystemQuickSaveHook
    {
    public:
        static void Hook()
        {
            REL::Relocation<uintptr_t> hook{ RELOCATION_ID(52378, 53274), 0x26};  //1408ef6f0		1.5.97 // 14098fe40 1.6.1170
            auto& trampoline = SKSE::GetTrampoline();
            SKSE::AllocTrampoline(1 << 4);
            _ProcessQuickSave = trampoline.write_branch<5>(hook.address(), ProcessQuickSave);
        };

    private:
        static void ProcessQuickSave(RE::BGSSaveLoadManager* a_manager, std::uint32_t a_flag);

        static inline REL::Relocation<decltype(ProcessQuickSave)> _ProcessQuickSave;
    };
} // namespace Hooks
