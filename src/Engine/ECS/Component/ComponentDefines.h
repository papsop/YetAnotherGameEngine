#pragma once

#include <bitset>

namespace Engine {

using T_ComponentId = uint32_t;
const T_ComponentId INVALID_COMPONENT_ID = ~static_cast<T_ComponentId>(0);

const T_ComponentId MAX_COMPONENTS = 64;
using T_Signature = std::bitset<MAX_COMPONENTS>;

}