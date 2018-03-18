#ifndef ATOM_NES_MEMORY_H
#define ATOM_NES_MEMORY_H

#include <array>

class Memory {
public:
  uint8_t get();
  uint8_t get16();

private:
  //std::array<uint8_t, 65535> mem;
};

#endif
