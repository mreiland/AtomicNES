#ifndef ATOMIC_NES_MEMORY_H
#define ATOMIC_NES_MEMORY_H

#include <array>
#include <vector>

class Memory {
public:
  uint8_t read8(uint16_t) const;
  uint16_t read16(uint16_t) const;

  void write8(uint16_t, uint8_t);
  void write16(uint16_t, uint16_t);

  std::array<uint8_t,65536> &raw();

private:
  std::array<uint8_t, 65536> mem;
};

#endif
