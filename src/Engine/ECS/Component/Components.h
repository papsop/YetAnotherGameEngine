#pragma once

#include <Engine/ECS/Component/ComponentDefines.h>

#include <raylib/src/raylib.h>

namespace Engine{

struct C_Transform
{
  Vector3 Position;
  Quaternion Rotation;
  Vector3 Scale;
};
// =====================================================

}