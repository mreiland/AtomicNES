#ifndef ATOM_NES_CPU_H
#define ATOM_NES_CPU_H

#include <cstdint>

struct Cpu {
  uint8_t a;
  uint8_t x;
  uint8_t y;
  
  uint16_t SP;
  uint8_t p;
};

#endif
