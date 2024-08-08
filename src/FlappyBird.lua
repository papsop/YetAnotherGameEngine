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

    vpaths { 
        ["Headers/"] = { "**.h", "**.inl" },
        ["Sources/"] = { "**.c", "**.cpp"},
    }

    links { "Engine" }

    files { flappyBirdPath .. "/**.cpp", flappyBirdPath .. "/**.h", flappyBirdPath .. "/**.inl"}