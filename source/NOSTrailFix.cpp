#include <windows.h>
#include <string>
#include <filesystem>
#include "MemoryTools.h"
#include "NOSTrailfix.h"

namespace {
    struct Config {
        int NosTrail = 1;
        float NOSTrailLength = 0.0f;
        float NOSTrailPositionScalar = 0.0f;
        int NOSFlareTrailPauseFix = 0;
        int NOSTrailFixForHighFPS = 1;
        float NOSTrailFadeOut = 40.0f;

        void Load() {
            char exePath[MAX_PATH] = { 0 };
            GetModuleFileNameA(NULL, exePath, MAX_PATH);
            std::filesystem::path gamePath = std::filesystem::path(exePath).parent_path();
            std::filesystem::path iniPath = gamePath / "scripts" / "NFSMW_NOSTrailFix.ini";
            if (!std::filesystem::exists(iniPath)) {
                iniPath = gamePath / "NFSMW_NOSTrailFix.ini";
            }

            std::string iniStr = iniPath.string();

            NosTrail = GetPrivateProfileIntA("NOSTRAIL", "NOSTrail", -1, iniStr.c_str());
            if (NosTrail == -1) NosTrail = GetPrivateProfileIntA("NOS TRAIL", "NOSTrail", 1, iniStr.c_str());

            char buf[64] = { 0 };
            GetPrivateProfileStringA("NOSTRAIL", "NOSTrailLength", "", buf, sizeof(buf), iniStr.c_str());
            if (!buf[0]) GetPrivateProfileStringA("NOS TRAIL", "NOSTrailLength", "0", buf, sizeof(buf), iniStr.c_str());
            NOSTrailLength = static_cast<float>(atof(buf));
            if (NOSTrailLength < 0.0f) NOSTrailLength = 0.0f;

            buf[0] = 0;
            GetPrivateProfileStringA("NOSTRAIL", "NOSTrailPositionScalar", "", buf, sizeof(buf), iniStr.c_str());
            if (!buf[0]) GetPrivateProfileStringA("NOS TRAIL", "NOSTrailPositionScalar", "0.0", buf, sizeof(buf), iniStr.c_str());
            NOSTrailPositionScalar = static_cast<float>(atof(buf));
            if (NOSTrailPositionScalar < 0.0f) NOSTrailPositionScalar = 0.0f;

            NOSFlareTrailPauseFix = GetPrivateProfileIntA("NOSTRAIL", "NOSFlareTrailPauseFix", -1, iniStr.c_str());
            if (NOSFlareTrailPauseFix == -1) NOSFlareTrailPauseFix = GetPrivateProfileIntA("NOS TRAIL", "NOSFlareTrailPauseFix", 0, iniStr.c_str());

            NOSTrailFixForHighFPS = GetPrivateProfileIntA("NOSTRAIL", "NOSTrailFixForHighFPS", -1, iniStr.c_str());
            if (NOSTrailFixForHighFPS == -1) NOSTrailFixForHighFPS = GetPrivateProfileIntA("NOS TRAIL", "NOSTrailFixForHighFPS", 1, iniStr.c_str());

            buf[0] = 0;
            GetPrivateProfileStringA("NOSTRAIL", "NOSTrailFadeOut", "", buf, sizeof(buf), iniStr.c_str());
            if (!buf[0]) GetPrivateProfileStringA("NOS TRAIL", "NOSTrailFadeOut", "40", buf, sizeof(buf), iniStr.c_str());
            NOSTrailFadeOut = static_cast<float>(atof(buf));
            if (NOSTrailFadeOut < 0.0f) NOSTrailFadeOut = 0.0f;
            if (NOSTrailFadeOut > 80.0f) NOSTrailFadeOut = 80.0f;
        }
    };

    inline int GetDesktopRefreshRate() {
        DEVMODEA dm = { 0 };
        dm.dmSize = sizeof(DEVMODEA);
        if (EnumDisplaySettingsA(NULL, ENUM_CURRENT_SETTINGS, &dm)) {
            if (dm.dmDisplayFrequency > 0) {
                return static_cast<int>(dm.dmDisplayFrequency);
            }
        }
        return 60;
    }

    void InitMod() {
        Config cfg;
        cfg.Load();

        float activeHz = static_cast<float>(GetDesktopRefreshRate());

        NOSTrailFix::Init(
            cfg.NosTrail != 0,
            cfg.NOSTrailLength,
            cfg.NOSTrailPositionScalar,
            cfg.NOSFlareTrailPauseFix != 0,
            cfg.NOSTrailFixForHighFPS != 0,
            activeHz,
            cfg.NOSTrailFadeOut
        );
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinstDLL);

        char moduleName[MAX_PATH] = { 0 };
        GetModuleFileNameA(NULL, moduleName, MAX_PATH);
        if (strstr(moduleName, "speed.exe") || strstr(moduleName, "SPEED.EXE")) {
            InitMod();
        }
    }
    return TRUE;
}
