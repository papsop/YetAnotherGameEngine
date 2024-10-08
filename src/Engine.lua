enginePath = "Engine/"

project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    architecture "x86_64"

    targetdir "../build/bin/%{cfg.buildcfg}"
    objdir "../build/obj/%{cfg.buildcfg}"

    includedirs
    {
        "../src",
        "../libs/",
        "../libs/spdlog/include/",
    }

    filter "action:vs*"
        defines{"_WINSOCK_DEPRECATED_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS"}
        dependson {"raylib"}
        links {"raylib.lib"}
        characterset ("MBCS")
        buildoptions { "/Zc:__cplusplus" }

    filter "system:windows"
        defines{"_WIN32", "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE"}
        links {"winmm", "gdi32"}
        libdirs {"../build/bin/%{cfg.buildcfg}"}

    files { enginePath .. "/**.cpp", enginePath .. "/**.h", enginePath .. "/**.inl"}