#pragma once
#include <type_traits>

namespace Engine {

template<typename...>
struct C_IdGenerator
{
  template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
  static T GetId()
  {
    static T nextId = 0;
    return nextId++;
  }
};

}