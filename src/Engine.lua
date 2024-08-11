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
    }

    filter "action:vs*"
        defines{"_WINSOCK_DEPRECATED_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS"}
        dependson {"raylib"}
        links {"raylib.lib"}
        characterset ("MBCS")
        buildoptions { "/Zc:__cplusplus" }

    filter "system:windows"
        defines{"_WIN32"}
        links {"winmm", "gdi32"}
        libdirs {"../build/bin/%{cfg.buildcfg}"}

    filter "configurations:Debug"
        defines { "DEBUG" }

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"

    files { enginePath .. "/**.cpp", enginePath .. "/**.h", enginePath .. "/**.inl"}