#pragma once
#include <Engine/Entity/EntityDefines.h>
#include <Engine/Component/IComponent.h>

#include <vector>

namespace Engine
{
  class C_Entity
  {
  public:
    C_Entity();
    C_Entity(const C_Entity&) = delete;
    C_Entity& operator=(const C_Entity&) = delete;
    ~C_Entity() = default;



  private:
    const EntityId m_Id;
    std::vector<I_Component*> m_Components;
  };
}