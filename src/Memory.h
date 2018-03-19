#ifndef ATOM_NES_MEMORY_H
#define ATOM_NES_MEMORY_H

#include <array>

class Memory {
public:
  uint8_t read8(uint16_t);
  uint8_t read16(uint16_t);

  void write8(uint16_t, uint8_t);
  void write16(uint16_t, uint16_t);

private:
  std::array<uint8_t, 65535> mem;
};

#endif
