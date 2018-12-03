#include "logger/nestest.h"

#include "fmt/format.h"
#include "error/unimplemented_error.h"

#include <iomanip>
#include <iostream>

using namespace logger;

NesTest::NesTest(const std::string &logfile) {
  this->fout_ptr = new std::ofstream(logfile, std::ios::trunc);
}
NesTest::~NesTest() {
  if(this->fout_ptr== nullptr) return;
  if(this->fout_ptr->is_open()) this->fout_ptr->close();
  delete this->fout_ptr;
}

void NesTest::log(const Cpu &cpu, const Memory &mem, const DecodeInfo &decoded) {
  std::ofstream &fout = *this->fout_ptr;

  fout << fmt::format("{:>04X}  ", cpu.PC);
  fout << fmt::format("{:>02X} ", mem.read8(cpu.PC));
  if(decoded.instruction->len > 1) fout << fmt::format("{:>02X} ", mem.read8(cpu.PC+1));
  if(decoded.instruction->len > 2) fout << fmt::format("{:>02X}  ", mem.read8(cpu.PC+2));

  if(decoded.instruction->len == 1) fout << "       ";
  if(decoded.instruction->len == 2) fout << "    ";

  fout << fmt::format("{} ", to_string(decoded.instruction->operation));
  std::string str = "";

  switch(decoded.instruction->mode) {
    case AddressingMode::Accum: throw error::unimplemented_error("Accumulator addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::IMM:
      str = fmt::format("#${:>02X} ", decoded.val1);
      break;
    case AddressingMode::Impl:
      break;
    case AddressingMode::Rel:
      // the PC will typically be incremented after the jump and the 6502 relies on this behavior
      // to get a larger range without having to store more bytes.  This displays the "true"
      // address even though the actual given address is a few bytes back
      //
      if(decoded.val1 > 127) str = fmt::format("${:>02X} ", decoded.addr1 - decoded.instruction->len);
      else                   str = fmt::format("${:>02X} ", decoded.addr1 + decoded.instruction->len);
      break;
    case AddressingMode::ZP:
      str = fmt::format("${:>02X} = {:>02X} ", decoded.addr1, decoded.val1);
      break;
    case AddressingMode::ZPX:   throw error::unimplemented_error("ZeroPage,X addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::ZPY:   throw error::unimplemented_error("ZeroPage,Y addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::ABS: {
      str = fmt::format("${:>02X}{:>02X} ", mem.read8(cpu.PC+2), mem.read8(cpu.PC+1));

      // I'm unsure why these instructions output differently even though they're ABS addressing mode
      //
      auto opcode = decoded.instruction->opcode;
      if(opcode == 0x8E || opcode == 0xAE || opcode == 0xAD) {
        str += fmt::format("= {:>02X} ",decoded.val1);
      }
      // 0x8E seems to be a 1 off in that it's ABS, but has = 00 after it in the logs.  investigate
      break;
    }
    case AddressingMode::ABSX:  throw error::unimplemented_error("Absolute,X addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::ABSY:  throw error::unimplemented_error("Absolute,Y  addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::IND:   throw error::unimplemented_error("Indirect addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::INDX:  throw error::unimplemented_error("Indirect,X addressing mode is not implemented IN THE LOGGER"); break;
    case AddressingMode::INDY:  throw error::unimplemented_error("Indirect,Y addressing mode is not implemented IN THE LOGGER"); break;
  }
  auto spaces_needed = 33 - str.length();

  fout << str;
  fout << std::setw(spaces_needed) << fmt::format("A:{:>02X} ", cpu.a);
  fout << fmt::format("X:{:>02X} ", cpu.x);
  fout << fmt::format("Y:{:>02X} ", cpu.y);
  fout << fmt::format("P:{:>02X} ", cpu.get_flags());
  fout << fmt::format("SP:{:>02X}", cpu.SP);

  fout << "\n";
}

