workspace "YetAnotherGameEngine"
    configurations { "Debug", "Release" }
    startproject "FlappyBird"
    location "project/"
    flags { "MultiProcessorCompile" }


-- Libs
group "Dependencies"
    include "libs/raylib.lua"
group ""

-- Engine
include "src/Engine.lua"

-- Games
include "src/FlappyBird.lua"
