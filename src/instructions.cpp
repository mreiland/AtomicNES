#include "instructions.h"

#include <array>

namespace {
  std::array<Instruction, 256> instr_tbl;
  
  Instruction make_instruction(uint8_t value,
                               operation opc,
                               addressing_mode mode,
                               uint8_t len,
                               uint8_t cycles,
                               uint8_t page_cycles)
  {
    
    if(value < 0 || value > 256)           throw "value is incorrect";
    if(len < 0 || len > 2)                 throw "len is incorrect";
    if(cycles < 0 || cycles > 7)           throw "cycles is incorrect";
    if(page_cycles < 0 || page_cycles > 2) throw "page_cycles is incorrect";
    
    Instruction instr  = { 
      .opcode = value,
      .opcode_type = opc,
      .addr_mode_type = mode,
      .len = len,
      .cycles = cycles,
      .page_cycles = page_cycles
    };
    return instr;
  }
}

namespace instructions {
  Instruction *get_instruction(int opcode_value) {
    return &instr_tbl[opcode_value];
  }
  void initialize() {
    instr_tbl[0x69] = make_instruction(0x69,operation::ADC, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x65] = make_instruction(0x65,operation::ADC, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x75] = make_instruction(0x75,operation::ADC, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x6D] = make_instruction(0x6D,operation::ADC, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x7D] = make_instruction(0x7D,operation::ADC, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x79] = make_instruction(0x79,operation::ADC, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x61] = make_instruction(0x61,operation::ADC, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x71] = make_instruction(0x71,operation::ADC, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x29] = make_instruction(0x29,operation::AND, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x25] = make_instruction(0x25,operation::AND, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x35] = make_instruction(0x35,operation::AND, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x2D] = make_instruction(0x2D,operation::AND, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x3D] = make_instruction(0x3D,operation::AND, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x39] = make_instruction(0x39,operation::AND, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x21] = make_instruction(0x21,operation::AND, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x31] = make_instruction(0x31,operation::AND, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x0A] = make_instruction(0x0A,operation::ASL, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x06] = make_instruction(0x06,operation::ASL, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x16] = make_instruction(0x16,operation::ASL, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x0E] = make_instruction(0x0E,operation::ASL, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x1E] = make_instruction(0x1E,operation::ASL, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0x90] = make_instruction(0x90,operation::BCC, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0xB0] = make_instruction(0xB0,operation::BCS, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0xF0] = make_instruction(0xF0,operation::BEQ, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear

    instr_tbl[0x24] = make_instruction(0x24,operation::BIT, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x2C] = make_instruction(0x2C,operation::BIT, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0x30] = make_instruction(0x30,operation::BMI, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0xD0] = make_instruction(0xD0,operation::BNE, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0x10] = make_instruction(0x10,operation::BPL, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    
    instr_tbl[0x00] = make_instruction(0x00,operation::BRK, addressing_mode::Impl,  1, 7, 0);

    instr_tbl[0x50] = make_instruction(0x50,operation::BVC, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0x70] = make_instruction(0x70,operation::BVS, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear

    instr_tbl[0x18] = make_instruction(0x18,operation::CLC, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xD8] = make_instruction(0xD8,operation::CLD, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x58] = make_instruction(0x58,operation::CLI, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xB8] = make_instruction(0xB8,operation::CLV, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0xC9] = make_instruction(0xC9,operation::CMP, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xC5] = make_instruction(0xC5,operation::CMP, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xD5] = make_instruction(0xD5,operation::CMP, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xCD] = make_instruction(0xCD,operation::CMP, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xDD] = make_instruction(0xDD,operation::CMP, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0xD9] = make_instruction(0xD9,operation::CMP, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0xC1] = make_instruction(0xC1,operation::CMP, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0xD1] = make_instruction(0xD1,operation::CMP, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0xE0] = make_instruction(0xE0,operation::CPX, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xE4] = make_instruction(0xE4,operation::CPX, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xEC] = make_instruction(0xEC,operation::CPX, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0xC0] = make_instruction(0xC0,operation::CPY, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xC4] = make_instruction(0xC4,operation::CPY, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xCC] = make_instruction(0xCC,operation::CPY, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0xC6] = make_instruction(0xC6,operation::DEC, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0xD6] = make_instruction(0xD6,operation::DEC, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0xCE] = make_instruction(0xCE,operation::DEC, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0xDE] = make_instruction(0xDE,operation::DEC, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0xCA] = make_instruction(0xCA,operation::DEX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x88] = make_instruction(0x88,operation::DEY, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x49] = make_instruction(0x49,operation::EOR, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x45] = make_instruction(0x45,operation::EOR, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x55] = make_instruction(0x55,operation::EOR, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x4D] = make_instruction(0x4D,operation::EOR, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x5D] = make_instruction(0x5D,operation::EOR, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x59] = make_instruction(0x59,operation::EOR, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x41] = make_instruction(0x41,operation::EOR, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x51] = make_instruction(0x51,operation::EOR, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0xE6] = make_instruction(0xE6,operation::INC, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0xF6] = make_instruction(0xF6,operation::INC, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0xEE] = make_instruction(0xEE,operation::INC, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0xEF] = make_instruction(0xEF,operation::INC, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0xE8] = make_instruction(0xE8,operation::INX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xC8] = make_instruction(0xC8,operation::INY, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x4C] = make_instruction(0x4C,operation::JMP, addressing_mode::ABS,   3, 3, 0);
    instr_tbl[0x6C] = make_instruction(0x6C,operation::JMP, addressing_mode::IND,   3, 5, 0);

    instr_tbl[0x20] = make_instruction(0x20,operation::JSR, addressing_mode::ABS,   3, 6, 0);

    instr_tbl[0xA9] = make_instruction(0xA9,operation::LDA, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xA5] = make_instruction(0xA5,operation::LDA, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xB5] = make_instruction(0xB5,operation::LDA, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xAD] = make_instruction(0xAD,operation::LDA, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xBD] = make_instruction(0xBD,operation::LDA, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0xB9] = make_instruction(0xB9,operation::LDA, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0xA1] = make_instruction(0xA1,operation::LDA, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0xB1] = make_instruction(0xB1,operation::LDA, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0xA2] = make_instruction(0xA2,operation::LDX, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xA6] = make_instruction(0xA6,operation::LDX, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xB6] = make_instruction(0xB6,operation::LDX, addressing_mode::ZPY,   2, 4, 0);
    instr_tbl[0xAE] = make_instruction(0xAE,operation::LDX, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xBE] = make_instruction(0xBE,operation::LDX, addressing_mode::ABSY,  3, 4, 1);

    instr_tbl[0xA0] = make_instruction(0xA0,operation::LDY, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xA4] = make_instruction(0xA4,operation::LDY, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xB4] = make_instruction(0xB4,operation::LDY, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xAC] = make_instruction(0xAC,operation::LDY, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xBC] = make_instruction(0xBC,operation::LDY, addressing_mode::ABSX,  3, 4, 1);

    instr_tbl[0x4A] = make_instruction(0x4A,operation::LSR, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x46] = make_instruction(0x46,operation::LSR, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x56] = make_instruction(0x56,operation::LSR, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x4E] = make_instruction(0x4E,operation::LSR, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x5E] = make_instruction(0x5E,operation::LSR, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0xEA] = make_instruction(0xEA,operation::NOP, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x09] = make_instruction(0x09,operation::ORA, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x05] = make_instruction(0x05,operation::ORA, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x15] = make_instruction(0x15,operation::ORA, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x0D] = make_instruction(0x0D,operation::ORA, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x1D] = make_instruction(0x1D,operation::ORA, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x19] = make_instruction(0x19,operation::ORA, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x01] = make_instruction(0x01,operation::ORA, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x11] = make_instruction(0x11,operation::ORA, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x48] = make_instruction(0x48,operation::PHA, addressing_mode::Impl,  1, 3, 0);
    instr_tbl[0x08] = make_instruction(0x08,operation::PHP, addressing_mode::Impl,  1, 3, 0);
    instr_tbl[0x68] = make_instruction(0x68,operation::PLA, addressing_mode::Impl,  1, 4, 0);
    instr_tbl[0x28] = make_instruction(0x28,operation::PLP, addressing_mode::Impl,  1, 4, 0);

    instr_tbl[0x2A] = make_instruction(0x2A,operation::ROL, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x26] = make_instruction(0x26,operation::ROL, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x36] = make_instruction(0x36,operation::ROL, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x2E] = make_instruction(0x2E,operation::ROL, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x3E] = make_instruction(0x3E,operation::ROL, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0x6A] = make_instruction(0x6A,operation::ROR, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x66] = make_instruction(0x66,operation::ROR, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x76] = make_instruction(0x76,operation::ROR, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x6E] = make_instruction(0x6E,operation::ROR, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x7E] = make_instruction(0x7E,operation::ROR, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0x40] = make_instruction(0x40,operation::RTI, addressing_mode::Impl,  1, 6, 0);
    instr_tbl[0x60] = make_instruction(0x60,operation::RTS, addressing_mode::Impl,  1, 6, 0);

    instr_tbl[0xE9] = make_instruction(0xE9,operation::SBC, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xE5] = make_instruction(0xE5,operation::SBC, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xF5] = make_instruction(0xF5,operation::SBC, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xED] = make_instruction(0xED,operation::SBC, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xFD] = make_instruction(0xFD,operation::SBC, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0xF9] = make_instruction(0xF9,operation::SBC, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0xE1] = make_instruction(0xE1,operation::SBC, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0xF1] = make_instruction(0xF1,operation::SBC, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x38] = make_instruction(0x38,operation::SEC, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xF8] = make_instruction(0xF8,operation::SED, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x78] = make_instruction(0x78,operation::SEI, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x85] = make_instruction(0x85,operation::STA, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x95] = make_instruction(0x95,operation::STA, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x8D] = make_instruction(0x8D,operation::STA, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x9D] = make_instruction(0x9D,operation::STA, addressing_mode::ABSX,  3, 5, 0);
    instr_tbl[0x99] = make_instruction(0x99,operation::STA, addressing_mode::ABSY,  3, 5, 0);
    instr_tbl[0x81] = make_instruction(0x81,operation::STA, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x91] = make_instruction(0x91,operation::STA, addressing_mode::INDY,  2, 6, 0);

    instr_tbl[0x86] = make_instruction(0x86,operation::STX, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x96] = make_instruction(0x96,operation::STX, addressing_mode::ZPY,   2, 4, 0);
    instr_tbl[0x8E] = make_instruction(0x8E,operation::STX, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0x84] = make_instruction(0x84,operation::STY, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x94] = make_instruction(0x94,operation::STY, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x8C] = make_instruction(0x8C,operation::STY, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0xAA] = make_instruction(0xAA,operation::TAX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xA8] = make_instruction(0xA8,operation::TAY, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xBA] = make_instruction(0xBA,operation::TSX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x8A] = make_instruction(0x8A,operation::TXA, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x9A] = make_instruction(0x9A,operation::TXS, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x98] = make_instruction(0x98,operation::TYA, addressing_mode::Impl,  1, 2, 0);


     
// ---------------- UNKNOWN/ILLEGAL OPCODES
     
//     instr_tbl[0x02] = make_instruction(0x02,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x03] = make_instruction(0x03,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x04] = make_instruction(0x04,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x07] = make_instruction(0x07,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x0B] = make_instruction(0x0B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x0C] = make_instruction(0x0C,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x0F] = make_instruction(0x0F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x12] = make_instruction(0x12,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x13] = make_instruction(0x13,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x14] = make_instruction(0x14,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x17] = make_instruction(0x17,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x1A] = make_instruction(0x1A,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x1B] = make_instruction(0x1B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x1C] = make_instruction(0x1C,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x1F] = make_instruction(0x1F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x22] = make_instruction(0x22,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x23] = make_instruction(0x23,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x27] = make_instruction(0x27,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x2B] = make_instruction(0x2B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x2F] = make_instruction(0x2F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x32] = make_instruction(0x32,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x33] = make_instruction(0x33,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x34] = make_instruction(0x34,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x37] = make_instruction(0x37,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x3A] = make_instruction(0x3A,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x3B] = make_instruction(0x3B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x3C] = make_instruction(0x3C,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x3F] = make_instruction(0x3F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x42] = make_instruction(0x42,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x43] = make_instruction(0x43,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x44] = make_instruction(0x44,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x47] = make_instruction(0x47,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x4B] = make_instruction(0x4B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x4F] = make_instruction(0x4F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x52] = make_instruction(0x52,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x53] = make_instruction(0x53,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x54] = make_instruction(0x54,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x57] = make_instruction(0x57,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x5A] = make_instruction(0x5A,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x5B] = make_instruction(0x5B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x5C] = make_instruction(0x5C,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x5F] = make_instruction(0x5F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x62] = make_instruction(0x62,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x63] = make_instruction(0x63,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x64] = make_instruction(0x64,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x67] = make_instruction(0x67,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x6B] = make_instruction(0x6B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x6F] = make_instruction(0x6F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x72] = make_instruction(0x72,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x73] = make_instruction(0x73,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x74] = make_instruction(0x74,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x77] = make_instruction(0x77,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x7A] = make_instruction(0x7A,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x7B] = make_instruction(0x7B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x7C] = make_instruction(0x7C,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x7F] = make_instruction(0x7F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x80] = make_instruction(0x80,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x82] = make_instruction(0x82,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x83] = make_instruction(0x83,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x87] = make_instruction(0x87,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x89] = make_instruction(0x89,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x8B] = make_instruction(0x8B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x8F] = make_instruction(0x8F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x92] = make_instruction(0x92,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x93] = make_instruction(0x93,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x97] = make_instruction(0x97,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x9B] = make_instruction(0x9B,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x9C] = make_instruction(0x9C,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x9E] = make_instruction(0x9E,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0x9F] = make_instruction(0x9F,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xA3] = make_instruction(0xA3,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xA7] = make_instruction(0xA7,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xAB] = make_instruction(0xAB,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xAF] = make_instruction(0xAF,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xB2] = make_instruction(0xB2,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xB3] = make_instruction(0xB3,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xB7] = make_instruction(0xB7,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xBB] = make_instruction(0xBB,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xBF] = make_instruction(0xBF,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xC2] = make_instruction(0xC2,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xC3] = make_instruction(0xC3,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xC7] = make_instruction(0xC7,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xCB] = make_instruction(0xCB,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xCF] = make_instruction(0xCF,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xD2] = make_instruction(0xD2,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xD3] = make_instruction(0xD3,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xD4] = make_instruction(0xD4,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xD7] = make_instruction(0xD7,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xDA] = make_instruction(0xDA,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xDB] = make_instruction(0xDB,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xDC] = make_instruction(0xDC,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xDF] = make_instruction(0xDF,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xE2] = make_instruction(0xE2,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xE3] = make_instruction(0xE3,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xE7] = make_instruction(0xE7,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xEB] = make_instruction(0xEB,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xF2] = make_instruction(0xF2,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xF3] = make_instruction(0xF3,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xF4] = make_instruction(0xF4,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xF7] = make_instruction(0xF7,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xFA] = make_instruction(0xFA,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xFB] = make_instruction(0xFB,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xFC] = make_instruction(0xFC,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xFE] = make_instruction(0xFE,operation::None, addressing_mode::None,   -1, -1);
//     instr_tbl[0xFF] = make_instruction(0xFF,operation::None, addressing_mode::None,   -1, -1);
  }
}
