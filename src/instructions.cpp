#include "instructions.h"

#include <array>

namespace {
  std::array<Instruction, 256> instructions_array;
  
  Instruction make_instruction(int value, opcode opc, addr_mode mode, int len, int cycles, int page_cycles) {
    
    if(value < 0 || value > 256)           throw "value is incorrect";
    if(len < 0 || len > 2)                 throw "len is incorrect";
    if(cycles < 0 || cycles > 7)           throw "cycles is incorrect";
    if(page_cycles < 0 || page_cycles > 2) throw "page_cycles is incorrect";
    
    Instruction instr  = { 
      .opcode_value = value,
      .opcode_class = opc,
      .addr_mode_class = mode,
      .len = len,
      .cycles = cycles,
      .page_cycles = page_cycles
    };
    return instr;
  }
}

namespace instructions {
  Instruction get_instruction(int opcode_value) {
    return instructions_array[opcode_value];
  }
  void initialize() {
    instructions_array[0x69] = make_instruction(0x69,opcode::ADC, addr_mode::IMM,     2, 2, 0);
    instructions_array[0x65] = make_instruction(0x65,opcode::ADC, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x75] = make_instruction(0x75,opcode::ADC, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0x6D] = make_instruction(0x6D,opcode::ADC, addr_mode::ABS,     3, 4, 0);
    instructions_array[0x7D] = make_instruction(0x7D,opcode::ADC, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0x79] = make_instruction(0x79,opcode::ADC, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0x61] = make_instruction(0x61,opcode::ADC, addr_mode::INDX,    2, 6, 0);
    instructions_array[0x71] = make_instruction(0x71,opcode::ADC, addr_mode::INDY,    2, 5, 1);

    instructions_array[0x29] = make_instruction(0x29,opcode::AND, addr_mode::IMM,     2, 2, 0);
    instructions_array[0x25] = make_instruction(0x25,opcode::AND, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x35] = make_instruction(0x35,opcode::AND, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0x2D] = make_instruction(0x2D,opcode::AND, addr_mode::ABS,     3, 4, 0);
    instructions_array[0x3D] = make_instruction(0x3D,opcode::AND, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0x39] = make_instruction(0x39,opcode::AND, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0x21] = make_instruction(0x21,opcode::AND, addr_mode::INDX,    2, 6, 0);
    instructions_array[0x31] = make_instruction(0x31,opcode::AND, addr_mode::INDY,    2, 5, 1);

    instructions_array[0x0A] = make_instruction(0x0A,opcode::ASL, addr_mode::Accum,   1, 2, 0);
    instructions_array[0x06] = make_instruction(0x06,opcode::ASL, addr_mode::ZP,      2, 5, 0);
    instructions_array[0x16] = make_instruction(0x16,opcode::ASL, addr_mode::ZPX,     2, 6, 0);
    instructions_array[0x0E] = make_instruction(0x0E,opcode::ASL, addr_mode::ABS,     3, 6, 0);
    instructions_array[0x1E] = make_instruction(0x1E,opcode::ASL, addr_mode::ABSX,    3, 7, 0);

    instructions_array[0x90] = make_instruction(0x90,opcode::BCC, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear
    instructions_array[0xB0] = make_instruction(0xB0,opcode::BCS, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear
    instructions_array[0xF0] = make_instruction(0xF0,opcode::BEQ, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear

    instructions_array[0x24] = make_instruction(0x24,opcode::BIT, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x2C] = make_instruction(0x2C,opcode::BIT, addr_mode::ABS,     3, 4, 0);

    instructions_array[0x30] = make_instruction(0x30,opcode::BMI, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear
    instructions_array[0xD0] = make_instruction(0xD0,opcode::BNE, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear
    instructions_array[0x10] = make_instruction(0x10,opcode::BPL, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear
    
    instructions_array[0x00] = make_instruction(0x00,opcode::BRK, addr_mode::Implied, 1, 7, 0);

    instructions_array[0x50] = make_instruction(0x50,opcode::BVC, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear
    instructions_array[0x70] = make_instruction(0x70,opcode::BVS, addr_mode::Rel,     2, 2, 2); // TODO: look closer at this, the description isn't clear

    instructions_array[0x18] = make_instruction(0x18,opcode::CLC, addr_mode::Implied, 1, 2, 0);
    instructions_array[0xD8] = make_instruction(0xD8,opcode::CLD, addr_mode::Implied, 1, 2, 0);
    instructions_array[0x58] = make_instruction(0x58,opcode::CLI, addr_mode::Implied, 1, 2, 0);
    instructions_array[0xB8] = make_instruction(0xB8,opcode::CLV, addr_mode::Implied, 1, 2, 0);

    instructions_array[0xC9] = make_instruction(0xC9,opcode::CMP, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xC5] = make_instruction(0xC5,opcode::CMP, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xD5] = make_instruction(0xD5,opcode::CMP, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0xCD] = make_instruction(0xCD,opcode::CMP, addr_mode::ABS,     3, 4, 0);
    instructions_array[0xDD] = make_instruction(0xDD,opcode::CMP, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0xD9] = make_instruction(0xD9,opcode::CMP, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0xC1] = make_instruction(0xC1,opcode::CMP, addr_mode::INDX,    2, 6, 0);
    instructions_array[0xD1] = make_instruction(0xD1,opcode::CMP, addr_mode::INDY,    2, 5, 1);

    instructions_array[0xE0] = make_instruction(0xE0,opcode::CPX, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xE4] = make_instruction(0xE4,opcode::CPX, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xEC] = make_instruction(0xEC,opcode::CPX, addr_mode::ABS,     3, 4, 0);

    instructions_array[0xC0] = make_instruction(0xC0,opcode::CPY, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xC4] = make_instruction(0xC4,opcode::CPY, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xCC] = make_instruction(0xCC,opcode::CPY, addr_mode::ABS,     3, 4, 0);

    instructions_array[0xC6] = make_instruction(0xC6,opcode::DEC, addr_mode::ZP,      2, 5, 0);
    instructions_array[0xD6] = make_instruction(0xD6,opcode::DEC, addr_mode::ZPX,     2, 6, 0);
    instructions_array[0xCE] = make_instruction(0xCE,opcode::DEC, addr_mode::ABS,     3, 6, 0);
    instructions_array[0xDE] = make_instruction(0xDE,opcode::DEC, addr_mode::ABSX,    3, 7, 0);

    instructions_array[0xCA] = make_instruction(0xCA,opcode::DEX, addr_mode::Implied, 1, 2, 0);
    instructions_array[0x88] = make_instruction(0x88,opcode::DEY, addr_mode::Implied, 1, 2, 0);

    instructions_array[0x49] = make_instruction(0x49,opcode::EOR, addr_mode::IMM,     2, 2, 0);
    instructions_array[0x45] = make_instruction(0x45,opcode::EOR, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x55] = make_instruction(0x55,opcode::EOR, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0x4D] = make_instruction(0x4D,opcode::EOR, addr_mode::ABS,     3, 4, 0);
    instructions_array[0x5D] = make_instruction(0x5D,opcode::EOR, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0x59] = make_instruction(0x59,opcode::EOR, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0x41] = make_instruction(0x41,opcode::EOR, addr_mode::INDX,    2, 6, 0);
    instructions_array[0x51] = make_instruction(0x51,opcode::EOR, addr_mode::INDY,    2, 5, 1);

    instructions_array[0xE6] = make_instruction(0xE6,opcode::INC, addr_mode::ZP,      2, 5, 0);
    instructions_array[0xF6] = make_instruction(0xF6,opcode::INC, addr_mode::ZPX,     2, 6, 0);
    instructions_array[0xEE] = make_instruction(0xEE,opcode::INC, addr_mode::ABS,     3, 6, 0);
    instructions_array[0xEF] = make_instruction(0xEF,opcode::INC, addr_mode::ABSX,    3, 7, 0);

    instructions_array[0xE8] = make_instruction(0xE8,opcode::INX, addr_mode::Implied, 1, 2, 0);
    instructions_array[0xC8] = make_instruction(0xC8,opcode::INY, addr_mode::Implied, 1, 2, 0);

    instructions_array[0x4C] = make_instruction(0x4C,opcode::JMP, addr_mode::ABS,     3, 3, 0);
    instructions_array[0x6C] = make_instruction(0x6C,opcode::JMP, addr_mode::IND,     3, 5, 0);

    instructions_array[0x20] = make_instruction(0x20,opcode::JSR, addr_mode::ABS,     3, 6, 0);

    instructions_array[0xA9] = make_instruction(0xA9,opcode::LDA, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xA5] = make_instruction(0xA5,opcode::LDA, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xB5] = make_instruction(0xB5,opcode::LDA, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0xAD] = make_instruction(0xAD,opcode::LDA, addr_mode::ABS,     3, 4, 0);
    instructions_array[0xBD] = make_instruction(0xBD,opcode::LDA, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0xB9] = make_instruction(0xB9,opcode::LDA, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0xA1] = make_instruction(0xA1,opcode::LDA, addr_mode::INDX,    2, 6, 0);
    instructions_array[0xB1] = make_instruction(0xB1,opcode::LDA, addr_mode::INDY,    2, 5, 1);

    instructions_array[0xA2] = make_instruction(0xA2,opcode::LDX, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xA6] = make_instruction(0xA6,opcode::LDX, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xB6] = make_instruction(0xB6,opcode::LDX, addr_mode::ZPY,     2, 4, 0);
    instructions_array[0xAE] = make_instruction(0xAE,opcode::LDX, addr_mode::ABS,     3, 4, 0);
    instructions_array[0xBE] = make_instruction(0xBE,opcode::LDX, addr_mode::ABSY,    3, 4, 1);

    instructions_array[0xA0] = make_instruction(0xA0,opcode::LDY, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xA4] = make_instruction(0xA4,opcode::LDY, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xB4] = make_instruction(0xB4,opcode::LDY, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0xAC] = make_instruction(0xAC,opcode::LDY, addr_mode::ABS,     3, 4, 0);
    instructions_array[0xBC] = make_instruction(0xBC,opcode::LDY, addr_mode::ABSX,    3, 4, 1);

    instructions_array[0x4A] = make_instruction(0x4A,opcode::LSR, addr_mode::Accum,   1, 2, 0);
    instructions_array[0x46] = make_instruction(0x46,opcode::LSR, addr_mode::ZP,      2, 5, 0);
    instructions_array[0x56] = make_instruction(0x56,opcode::LSR, addr_mode::ZPX,     2, 6, 0);
    instructions_array[0x4E] = make_instruction(0x4E,opcode::LSR, addr_mode::ABS,     3, 6, 0);
    instructions_array[0x5E] = make_instruction(0x5E,opcode::LSR, addr_mode::ABSX,    3, 7, 0);

    instructions_array[0xEA] = make_instruction(0xEA,opcode::NOP, addr_mode::Implied, 1, 2, 0);

    instructions_array[0x09] = make_instruction(0x09,opcode::ORA, addr_mode::IMM,     2, 2, 0);
    instructions_array[0x05] = make_instruction(0x05,opcode::ORA, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x15] = make_instruction(0x15,opcode::ORA, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0x0D] = make_instruction(0x0D,opcode::ORA, addr_mode::ABS,     3, 4, 0);
    instructions_array[0x1D] = make_instruction(0x1D,opcode::ORA, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0x19] = make_instruction(0x19,opcode::ORA, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0x01] = make_instruction(0x01,opcode::ORA, addr_mode::INDX,    2, 6, 0);
    instructions_array[0x11] = make_instruction(0x11,opcode::ORA, addr_mode::INDY,    2, 5, 1);

    instructions_array[0x48] = make_instruction(0x48,opcode::PHA, addr_mode::Implied, 1, 3, 0);
    instructions_array[0x08] = make_instruction(0x08,opcode::PHP, addr_mode::Implied, 1, 3, 0);
    instructions_array[0x68] = make_instruction(0x68,opcode::PLA, addr_mode::Implied, 1, 4, 0);
    instructions_array[0x28] = make_instruction(0x28,opcode::PLP, addr_mode::Implied, 1, 4, 0);

    instructions_array[0x2A] = make_instruction(0x2A,opcode::ROL, addr_mode::Accum,   1, 2, 0);
    instructions_array[0x26] = make_instruction(0x26,opcode::ROL, addr_mode::ZP,      2, 5, 0);
    instructions_array[0x36] = make_instruction(0x36,opcode::ROL, addr_mode::ZPX,     2, 6, 0);
    instructions_array[0x2E] = make_instruction(0x2E,opcode::ROL, addr_mode::ABS,     3, 6, 0);
    instructions_array[0x3E] = make_instruction(0x3E,opcode::ROL, addr_mode::ABSX,    3, 7, 0);

    instructions_array[0x6A] = make_instruction(0x6A,opcode::ROR, addr_mode::Accum,   1, 2, 0);
    instructions_array[0x66] = make_instruction(0x66,opcode::ROR, addr_mode::ZP,      2, 5, 0);
    instructions_array[0x76] = make_instruction(0x76,opcode::ROR, addr_mode::ZPX,     2, 6, 0);
    instructions_array[0x6E] = make_instruction(0x6E,opcode::ROR, addr_mode::ABS,     3, 6, 0);
    instructions_array[0x7E] = make_instruction(0x7E,opcode::ROR, addr_mode::ABSX,    3, 7, 0);

    instructions_array[0x40] = make_instruction(0x40,opcode::RTI, addr_mode::Implied, 1, 6, 0);
    instructions_array[0x60] = make_instruction(0x60,opcode::RTS, addr_mode::Implied, 1, 6, 0);

    instructions_array[0xE9] = make_instruction(0xE9,opcode::SBC, addr_mode::IMM,     2, 2, 0);
    instructions_array[0xE5] = make_instruction(0xE5,opcode::SBC, addr_mode::ZP,      2, 3, 0);
    instructions_array[0xF5] = make_instruction(0xF5,opcode::SBC, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0xED] = make_instruction(0xED,opcode::SBC, addr_mode::ABS,     3, 4, 0);
    instructions_array[0xFD] = make_instruction(0xFD,opcode::SBC, addr_mode::ABSX,    3, 4, 1);
    instructions_array[0xF9] = make_instruction(0xF9,opcode::SBC, addr_mode::ABSY,    3, 4, 1);
    instructions_array[0xE1] = make_instruction(0xE1,opcode::SBC, addr_mode::INDX,    2, 6, 0);
    instructions_array[0xF1] = make_instruction(0xF1,opcode::SBC, addr_mode::INDY,    2, 5, 1);

    instructions_array[0x38] = make_instruction(0x38,opcode::SEC, addr_mode::Implied, 1, 2, 0);
    instructions_array[0xF8] = make_instruction(0xF8,opcode::SED, addr_mode::Implied, 1, 2, 0);
    instructions_array[0x78] = make_instruction(0x78,opcode::SEI, addr_mode::Implied, 1, 2, 0);

    instructions_array[0x85] = make_instruction(0x85,opcode::STA, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x95] = make_instruction(0x95,opcode::STA, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0x8D] = make_instruction(0x8D,opcode::STA, addr_mode::ABS,     3, 4, 0);
    instructions_array[0x9D] = make_instruction(0x9D,opcode::STA, addr_mode::ABSX,    3, 5, 0);
    instructions_array[0x99] = make_instruction(0x99,opcode::STA, addr_mode::ABSY,    3, 5, 0);
    instructions_array[0x81] = make_instruction(0x81,opcode::STA, addr_mode::INDX,    2, 6, 0);
    instructions_array[0x91] = make_instruction(0x91,opcode::STA, addr_mode::INDY,    2, 6, 0);

    instructions_array[0x86] = make_instruction(0x86,opcode::STX, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x96] = make_instruction(0x96,opcode::STX, addr_mode::ZPY,     2, 4, 0);
    instructions_array[0x8E] = make_instruction(0x8E,opcode::STX, addr_mode::ABS,     3, 4, 0);

    instructions_array[0x84] = make_instruction(0x84,opcode::STY, addr_mode::ZP,      2, 3, 0);
    instructions_array[0x94] = make_instruction(0x94,opcode::STY, addr_mode::ZPX,     2, 4, 0);
    instructions_array[0x8C] = make_instruction(0x8C,opcode::STY, addr_mode::ABS,     3, 4, 0);

    instructions_array[0xAA] = make_instruction(0xAA,opcode::TAX, addr_mode::Implied,   1, 2, 0);
    instructions_array[0xA8] = make_instruction(0xA8,opcode::TAY, addr_mode::Implied,   1, 2, 0);
    instructions_array[0xBA] = make_instruction(0xBA,opcode::TSX, addr_mode::Implied,   1, 2, 0);
    instructions_array[0x8A] = make_instruction(0x8A,opcode::TXA, addr_mode::Implied,   1, 2, 0);
    instructions_array[0x9A] = make_instruction(0x9A,opcode::TXS, addr_mode::Implied,   1, 2, 0);
    instructions_array[0x98] = make_instruction(0x98,opcode::TYA, addr_mode::Implied,   1, 2, 0);


     
// ---------------- UNKNOWN/ILLEGAL OPCODES
     
//     instructions_array[0x02] = make_instruction(0x02,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x03] = make_instruction(0x03,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x04] = make_instruction(0x04,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x07] = make_instruction(0x07,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x0B] = make_instruction(0x0B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x0C] = make_instruction(0x0C,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x0F] = make_instruction(0x0F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x12] = make_instruction(0x12,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x13] = make_instruction(0x13,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x14] = make_instruction(0x14,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x17] = make_instruction(0x17,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x1A] = make_instruction(0x1A,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x1B] = make_instruction(0x1B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x1C] = make_instruction(0x1C,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x1F] = make_instruction(0x1F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x22] = make_instruction(0x22,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x23] = make_instruction(0x23,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x27] = make_instruction(0x27,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x2B] = make_instruction(0x2B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x2F] = make_instruction(0x2F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x32] = make_instruction(0x32,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x33] = make_instruction(0x33,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x34] = make_instruction(0x34,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x37] = make_instruction(0x37,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x3A] = make_instruction(0x3A,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x3B] = make_instruction(0x3B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x3C] = make_instruction(0x3C,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x3F] = make_instruction(0x3F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x42] = make_instruction(0x42,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x43] = make_instruction(0x43,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x44] = make_instruction(0x44,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x47] = make_instruction(0x47,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x4B] = make_instruction(0x4B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x4F] = make_instruction(0x4F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x52] = make_instruction(0x52,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x53] = make_instruction(0x53,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x54] = make_instruction(0x54,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x57] = make_instruction(0x57,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x5A] = make_instruction(0x5A,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x5B] = make_instruction(0x5B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x5C] = make_instruction(0x5C,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x5F] = make_instruction(0x5F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x62] = make_instruction(0x62,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x63] = make_instruction(0x63,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x64] = make_instruction(0x64,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x67] = make_instruction(0x67,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x6B] = make_instruction(0x6B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x6F] = make_instruction(0x6F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x72] = make_instruction(0x72,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x73] = make_instruction(0x73,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x74] = make_instruction(0x74,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x77] = make_instruction(0x77,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x7A] = make_instruction(0x7A,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x7B] = make_instruction(0x7B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x7C] = make_instruction(0x7C,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x7F] = make_instruction(0x7F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x80] = make_instruction(0x80,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x82] = make_instruction(0x82,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x83] = make_instruction(0x83,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x87] = make_instruction(0x87,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x89] = make_instruction(0x89,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x8B] = make_instruction(0x8B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x8F] = make_instruction(0x8F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x92] = make_instruction(0x92,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x93] = make_instruction(0x93,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x97] = make_instruction(0x97,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x9B] = make_instruction(0x9B,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x9C] = make_instruction(0x9C,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x9E] = make_instruction(0x9E,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0x9F] = make_instruction(0x9F,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xA3] = make_instruction(0xA3,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xA7] = make_instruction(0xA7,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xAB] = make_instruction(0xAB,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xAF] = make_instruction(0xAF,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xB2] = make_instruction(0xB2,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xB3] = make_instruction(0xB3,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xB7] = make_instruction(0xB7,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xBB] = make_instruction(0xBB,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xBF] = make_instruction(0xBF,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xC2] = make_instruction(0xC2,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xC3] = make_instruction(0xC3,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xC7] = make_instruction(0xC7,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xCB] = make_instruction(0xCB,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xCF] = make_instruction(0xCF,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xD2] = make_instruction(0xD2,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xD3] = make_instruction(0xD3,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xD4] = make_instruction(0xD4,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xD7] = make_instruction(0xD7,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xDA] = make_instruction(0xDA,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xDB] = make_instruction(0xDB,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xDC] = make_instruction(0xDC,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xDF] = make_instruction(0xDF,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xE2] = make_instruction(0xE2,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xE3] = make_instruction(0xE3,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xE7] = make_instruction(0xE7,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xEB] = make_instruction(0xEB,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xF2] = make_instruction(0xF2,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xF3] = make_instruction(0xF3,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xF4] = make_instruction(0xF4,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xF7] = make_instruction(0xF7,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xFA] = make_instruction(0xFA,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xFB] = make_instruction(0xFB,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xFC] = make_instruction(0xFC,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xFE] = make_instruction(0xFE,opcode::None, addr_mode::None,   -1, -1);
//     instructions_array[0xFF] = make_instruction(0xFF,opcode::None, addr_mode::None,   -1, -1);
  }
}
