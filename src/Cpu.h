#ifndef ATOM_NES_CPU_H
#define ATOM_NES_CPU_H

#include <cstdint>

struct Cpu {
  // registers
  uint8_t a;
  uint8_t x;
  uint8_t y;

  uint16_t PC;
  uint8_t SP;

  // processor flags
  bool C;
  bool Z;
  bool I;
  bool D;
  bool B;
  bool U;
  bool V;
  bool N;

  inline void set_flags(uint8_t flags) {
    C = ((flags >> 0) & 1) > 0;
    Z = ((flags >> 1) & 1) > 0;
    I = ((flags >> 2) & 1) > 0;
    D = ((flags >> 3) & 1) > 0;
    B = ((flags >> 4) & 1) > 0;
    U = ((flags >> 5) & 1) > 0;
    V = ((flags >> 6) & 1) > 0;
    N = ((flags >> 7) & 1) > 0;
  }

  inline uint8_t get_flags() {
    uint8_t flags;
     flags = flags + (C << 0);
     flags = flags + (Z << 1);
     flags = flags + (I << 2);
     flags = flags + (D << 3);
     flags = flags + (B << 4);
     flags = flags + (U << 5);
     flags = flags + (V << 6);
     flags = flags + (N << 7);

    return flags;
  }
};

#endif
