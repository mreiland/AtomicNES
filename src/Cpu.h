#ifndef ATOMIC_NES_CPU_H
#define ATOMIC_NES_CPU_H

#include <cstdint>

struct Cpu {
  // registers
  uint8_t a;
  uint8_t x;
  uint8_t y;

  uint16_t PC;
  uint8_t SP;

  // processor flags
  bool C; // bit 0
  bool Z; // bit 1
  bool I; // bit 2
  bool D; // bit 3
  bool B; // bit 4
  bool U; // bit 5
  bool V; // bit 6
  bool N; // bit 7


  // note: bit 5 is always set to 0, but we leave the code in for clarity
  inline void set_flags(uint8_t flags) {
    C = ((flags >> 0) & 1) > 0;
    Z = ((flags >> 1) & 1) > 0;
    I = ((flags >> 2) & 1) > 0;
    D = ((flags >> 3) & 1) > 0;
    //B = ((flags >> 4) & 1) > 0;
    U = ((flags >> 5) & 1) > 0;
    V = ((flags >> 6) & 1) > 0;
    N = ((flags >> 7) & 1) > 0;
  }

  inline uint8_t get_flags() const {
    uint8_t flags = 0;
    flags = flags + (C << 0);
    flags = flags + (Z << 1);
    flags = flags + (I << 2);
    flags = flags + (D << 3);
    //flags = flags + (B << 4);
    flags = flags + (U << 5);
    flags = flags + (V << 6);
    flags = flags + (N << 7);

    return flags;
  }

  inline void set_Z(uint8_t val) {
    this->Z = val == 0;
  }
  inline void set_N(uint8_t val) {
    this->N = val > 127;
  }

  inline void compare(uint8_t a, uint8_t b) {
    uint8_t val = a-b;
    this->set_Z(val);
    this->set_N(val);
    this->C = a >= b;
  }
};

#endif
