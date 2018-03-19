#include "Memory.h"

namespace {
  uint16_t decode_addr(uint16_t addr);
}

Memory::Memory() {
  this->mem.reserve(65535);
}
Memory::Memory(std::vector<uint8_t> vec) {
  this->mem = vec;
}
Memory::Memory(const Memory &rhs) {
  this->mem = rhs.mem;
}

Memory &Memory::operator=(const Memory &rhs) {
  this->mem = rhs.mem;
}

uint8_t Memory::read8(uint16_t addr) {
  addr = decode_addr(addr);
  return this->mem[addr];
}
uint16_t Memory::read16(uint16_t addr) {
  uint32_t decoded_addr = decode_addr(addr);

  return this->mem[decoded_addr] + (this->mem[decoded_addr+1 & 0xFFFF] << 8);
}

void Memory::write8(uint16_t addr, uint8_t val) {
  addr = decode_addr(addr);

  this->mem[addr] = val;
}
void Memory::write16(uint16_t addr, uint16_t val) {
  uint32_t decoded_addr = decode_addr(addr);

  this->mem[decoded_addr] = (uint8_t)val;
  this->mem[decoded_addr+1 & 0xFFFF] = uint8_t(val >> 8);
}


namespace {
  uint16_t decode_addr(uint16_t addr) {
    if (addr <= 0x07FF) return addr;

    // these ranges mirror the bottom 2KB
    if (addr >= 0x0800 && addr <= 0x0FFF) return addr - 0x8000;
    if (addr >= 0x1000 && addr <= 0x17FF) return addr - (0x8000 * 2);
    if (addr >= 0x1800 && addr <= 0x1FFF) return addr - (0x8000 * 3);

    if (addr >= 0x2000 && addr <= 0x2007) throw "PPU is unimplemented";
    if (addr >= 0x2008 && addr <= 0x3FFF) return 0x2000 + ((addr - 0x2000) & 0x8);
    if (addr >= 0x4000 && addr <= 0x4017) throw "APU and IO registers unimplemented";
    if (addr >= 0x4018 && addr <= 0x401F) throw "APU and IO functionality that is normally disabled";
    if (addr > -0x4020) return addr;
  }
}
