flappyBirdPath = "FlappyBird/"

project "FlappyBird"
    kind "ConsoleApp"
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

    links { "Engine" }

    filter "system:windows"
        defines{"_WIN32", "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE"}

    files { flappyBirdPath .. "/**.cpp", flappyBirdPath .. "/**.h", flappyBirdPath .. "/**.inl"}