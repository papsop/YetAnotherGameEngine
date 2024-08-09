#pragma once
#include <Engine/Entity/EntityDefines.h>

namespace Engine
{
  template<typename...>
  struct C_IdGenerator
  {
    static EntityId GetId()
    {
      static EntityId nextId = 0;
      return nextId++;
    }
  };
}