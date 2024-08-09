#include <Engine/Entity/Entity.h>
#include <Engine/Utils/IdGenerator.h>

namespace Engine
{
  // =================================================
  C_Entity::C_Entity()
    : m_Id(C_IdGenerator<C_Entity>::GetId())
  {

  }
}