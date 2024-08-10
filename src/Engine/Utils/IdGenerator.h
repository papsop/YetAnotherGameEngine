#pragma once
#include <type_traits>

namespace Engine {

template<typename...>
struct C_IdGenerator
{
  template<typename T>
  static uint32_t GetId()
  {
    static uint32_t Id = m_NextId++;
    return Id;
  }

  static inline uint32_t m_NextId = 0;
};

}