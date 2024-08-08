function platform_defines()
    defines{"PLATFORM_DESKTOP"}

    filter {"options:graphics=opengl43"}
        defines{"GRAPHICS_API_OPENGL_43"}

    filter {"options:graphics=opengl33"}
        defines{"GRAPHICS_API_OPENGL_33"}

    filter {"options:graphics=opengl21"}
        defines{"GRAPHICS_API_OPENGL_21"}

    filter {"options:graphics=opengl11"}
        defines{"GRAPHICS_API_OPENGL_11"}

    filter {"options:graphics=openges3"}
        defines{"GRAPHICS_API_OPENGL_ES3"}

    filter {"options:graphics=openges2"}
        defines{"GRAPHICS_API_OPENGL_ES2"}

    filter {"system:macosx"}
        disablewarnings {"deprecated-declarations"}

    filter {"system:linux"}
        defines {"_GLFW_X11"}
        defines {"_GNU_SOURCE"}
-- This is necessary, otherwise compilation will fail since
-- there is no CLOCK_MONOTOMIC. raylib claims to have a workaround
-- to compile under c99 without -D_GNU_SOURCE, but it didn't seem
-- to work. raylib's Makefile also adds this flag, probably why it went
-- unnoticed for so long.
-- It compiles under c11 without -D_GNU_SOURCE, because c11 requires
-- to have CLOCK_MONOTOMIC
-- See: https://github.com/raysan5/raylib/issues/2729

    filter{}
end

-- =============================================================================

project "raylib"
    kind "StaticLib"

    platform_defines()

    language "C"
    architecture "x86_64"
    targetdir "../build/bin/%{cfg.buildcfg}"

    filter "action:vs*"
        defines{"_WINSOCK_DEPRECATED_NO_WARNINGS", "_CRT_SECURE_NO_WARNINGS"}
        characterset ("MBCS")
        buildoptions { "/Zc:__cplusplus" }
    filter{}

    includedirs 
    {
        "raylib/src", 
        "raylib/src/external/glfw/include" 
    }

    vpaths
    {
        ["Header Files"] = { "raylib/src/**.h"},
        ["Source Files/*"] = { "raylib/src/**.c"},
    }

    files {"raylib/src/*.h", "raylib/src/*.c"}

    removefiles { "raylib/src/rcore_*.c" }