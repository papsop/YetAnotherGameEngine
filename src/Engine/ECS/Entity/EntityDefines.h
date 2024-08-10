#pragma once

#include <cstdint>

namespace Engine{

using T_Entity = uint32_t;
const T_Entity INVALID_ENTITY_ID = ~static_cast<T_Entity>(0);

const T_Entity MAX_ENTITIES = 100;

}