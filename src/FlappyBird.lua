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
        "../libs/"
    }

    links { "Engine" }

    filter "configurations:Debug"
        defines { "DEBUG" }

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"

    files { flappyBirdPath .. "/**.cpp", flappyBirdPath .. "/**.h", flappyBirdPath .. "/**.inl"}