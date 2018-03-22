#include "Memory.h"
#include "error/unimplemented_error.h"

namespace {
  uint16_t decode_addr(uint16_t addr);
}

uint8_t Memory::read8(uint16_t addr) const {
  addr = decode_addr(addr);
  return this->mem[addr];
}
uint16_t Memory::read16(uint16_t addr) const {
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


std::array<uint8_t,65536> &Memory::raw() {
  return this->mem;
};


namespace {
  uint16_t decode_addr(uint16_t addr) {
    if(addr <= 0x1FFF) return uint16_t(addr & 0x07FF);

    if (addr >= 0x2000 && addr <= 0x2007) throw error::unimplemented_error("PPU is unimplemented");
    if (addr >= 0x2008 && addr <= 0x3FFF) return uint16_t(0x2000 + (addr & 0x8));
    if (addr >= 0x4000 && addr <= 0x4017) throw error::unimplemented_error("APU and IO registers unimplemented");
    if (addr >= 0x4018 && addr <= 0x401F) throw error::unimplemented_error("APU and IO functionality that is normally disabled");
    if (addr > 0x4020) return addr;
  }
}
