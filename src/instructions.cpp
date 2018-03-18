#include "instructions.h"

#include <array>

namespace {
  std::array<Instruction, 256> instr_tbl;
  
  Instruction make_instruction(int value, opcode opc, addressing_mode mode, int len, int cycles, int page_cycles) {
    
    if(value < 0 || value > 256)           throw "value is incorrect";
    if(len < 0 || len > 2)                 throw "len is incorrect";
    if(cycles < 0 || cycles > 7)           throw "cycles is incorrect";
    if(page_cycles < 0 || page_cycles > 2) throw "page_cycles is incorrect";
    
    Instruction instr  = { 
      .opcode_value = value,
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
  Instruction get_instruction(int opcode_value) {
    return instr_tbl[opcode_value];
  }
  void initialize() {
    instr_tbl[0x69] = make_instruction(0x69,opcode::ADC, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x65] = make_instruction(0x65,opcode::ADC, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x75] = make_instruction(0x75,opcode::ADC, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x6D] = make_instruction(0x6D,opcode::ADC, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x7D] = make_instruction(0x7D,opcode::ADC, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x79] = make_instruction(0x79,opcode::ADC, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x61] = make_instruction(0x61,opcode::ADC, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x71] = make_instruction(0x71,opcode::ADC, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x29] = make_instruction(0x29,opcode::AND, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x25] = make_instruction(0x25,opcode::AND, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x35] = make_instruction(0x35,opcode::AND, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x2D] = make_instruction(0x2D,opcode::AND, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x3D] = make_instruction(0x3D,opcode::AND, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x39] = make_instruction(0x39,opcode::AND, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x21] = make_instruction(0x21,opcode::AND, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x31] = make_instruction(0x31,opcode::AND, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x0A] = make_instruction(0x0A,opcode::ASL, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x06] = make_instruction(0x06,opcode::ASL, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x16] = make_instruction(0x16,opcode::ASL, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x0E] = make_instruction(0x0E,opcode::ASL, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x1E] = make_instruction(0x1E,opcode::ASL, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0x90] = make_instruction(0x90,opcode::BCC, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0xB0] = make_instruction(0xB0,opcode::BCS, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0xF0] = make_instruction(0xF0,opcode::BEQ, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear

    instr_tbl[0x24] = make_instruction(0x24,opcode::BIT, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x2C] = make_instruction(0x2C,opcode::BIT, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0x30] = make_instruction(0x30,opcode::BMI, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0xD0] = make_instruction(0xD0,opcode::BNE, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0x10] = make_instruction(0x10,opcode::BPL, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    
    instr_tbl[0x00] = make_instruction(0x00,opcode::BRK, addressing_mode::Impl,  1, 7, 0);

    instr_tbl[0x50] = make_instruction(0x50,opcode::BVC, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear
    instr_tbl[0x70] = make_instruction(0x70,opcode::BVS, addressing_mode::Rel,   2, 2, 2); // TODO: look closer at this, the description isn't clear

    instr_tbl[0x18] = make_instruction(0x18,opcode::CLC, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xD8] = make_instruction(0xD8,opcode::CLD, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x58] = make_instruction(0x58,opcode::CLI, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xB8] = make_instruction(0xB8,opcode::CLV, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0xC9] = make_instruction(0xC9,opcode::CMP, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xC5] = make_instruction(0xC5,opcode::CMP, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xD5] = make_instruction(0xD5,opcode::CMP, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xCD] = make_instruction(0xCD,opcode::CMP, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xDD] = make_instruction(0xDD,opcode::CMP, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0xD9] = make_instruction(0xD9,opcode::CMP, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0xC1] = make_instruction(0xC1,opcode::CMP, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0xD1] = make_instruction(0xD1,opcode::CMP, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0xE0] = make_instruction(0xE0,opcode::CPX, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xE4] = make_instruction(0xE4,opcode::CPX, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xEC] = make_instruction(0xEC,opcode::CPX, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0xC0] = make_instruction(0xC0,opcode::CPY, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xC4] = make_instruction(0xC4,opcode::CPY, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xCC] = make_instruction(0xCC,opcode::CPY, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0xC6] = make_instruction(0xC6,opcode::DEC, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0xD6] = make_instruction(0xD6,opcode::DEC, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0xCE] = make_instruction(0xCE,opcode::DEC, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0xDE] = make_instruction(0xDE,opcode::DEC, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0xCA] = make_instruction(0xCA,opcode::DEX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x88] = make_instruction(0x88,opcode::DEY, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x49] = make_instruction(0x49,opcode::EOR, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x45] = make_instruction(0x45,opcode::EOR, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x55] = make_instruction(0x55,opcode::EOR, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x4D] = make_instruction(0x4D,opcode::EOR, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x5D] = make_instruction(0x5D,opcode::EOR, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x59] = make_instruction(0x59,opcode::EOR, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x41] = make_instruction(0x41,opcode::EOR, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x51] = make_instruction(0x51,opcode::EOR, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0xE6] = make_instruction(0xE6,opcode::INC, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0xF6] = make_instruction(0xF6,opcode::INC, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0xEE] = make_instruction(0xEE,opcode::INC, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0xEF] = make_instruction(0xEF,opcode::INC, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0xE8] = make_instruction(0xE8,opcode::INX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xC8] = make_instruction(0xC8,opcode::INY, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x4C] = make_instruction(0x4C,opcode::JMP, addressing_mode::ABS,   3, 3, 0);
    instr_tbl[0x6C] = make_instruction(0x6C,opcode::JMP, addressing_mode::IND,   3, 5, 0);

    instr_tbl[0x20] = make_instruction(0x20,opcode::JSR, addressing_mode::ABS,   3, 6, 0);

    instr_tbl[0xA9] = make_instruction(0xA9,opcode::LDA, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xA5] = make_instruction(0xA5,opcode::LDA, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xB5] = make_instruction(0xB5,opcode::LDA, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xAD] = make_instruction(0xAD,opcode::LDA, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xBD] = make_instruction(0xBD,opcode::LDA, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0xB9] = make_instruction(0xB9,opcode::LDA, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0xA1] = make_instruction(0xA1,opcode::LDA, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0xB1] = make_instruction(0xB1,opcode::LDA, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0xA2] = make_instruction(0xA2,opcode::LDX, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xA6] = make_instruction(0xA6,opcode::LDX, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xB6] = make_instruction(0xB6,opcode::LDX, addressing_mode::ZPY,   2, 4, 0);
    instr_tbl[0xAE] = make_instruction(0xAE,opcode::LDX, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xBE] = make_instruction(0xBE,opcode::LDX, addressing_mode::ABSY,  3, 4, 1);

    instr_tbl[0xA0] = make_instruction(0xA0,opcode::LDY, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xA4] = make_instruction(0xA4,opcode::LDY, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xB4] = make_instruction(0xB4,opcode::LDY, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xAC] = make_instruction(0xAC,opcode::LDY, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xBC] = make_instruction(0xBC,opcode::LDY, addressing_mode::ABSX,  3, 4, 1);

    instr_tbl[0x4A] = make_instruction(0x4A,opcode::LSR, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x46] = make_instruction(0x46,opcode::LSR, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x56] = make_instruction(0x56,opcode::LSR, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x4E] = make_instruction(0x4E,opcode::LSR, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x5E] = make_instruction(0x5E,opcode::LSR, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0xEA] = make_instruction(0xEA,opcode::NOP, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x09] = make_instruction(0x09,opcode::ORA, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0x05] = make_instruction(0x05,opcode::ORA, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x15] = make_instruction(0x15,opcode::ORA, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x0D] = make_instruction(0x0D,opcode::ORA, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x1D] = make_instruction(0x1D,opcode::ORA, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0x19] = make_instruction(0x19,opcode::ORA, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0x01] = make_instruction(0x01,opcode::ORA, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x11] = make_instruction(0x11,opcode::ORA, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x48] = make_instruction(0x48,opcode::PHA, addressing_mode::Impl,  1, 3, 0);
    instr_tbl[0x08] = make_instruction(0x08,opcode::PHP, addressing_mode::Impl,  1, 3, 0);
    instr_tbl[0x68] = make_instruction(0x68,opcode::PLA, addressing_mode::Impl,  1, 4, 0);
    instr_tbl[0x28] = make_instruction(0x28,opcode::PLP, addressing_mode::Impl,  1, 4, 0);

    instr_tbl[0x2A] = make_instruction(0x2A,opcode::ROL, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x26] = make_instruction(0x26,opcode::ROL, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x36] = make_instruction(0x36,opcode::ROL, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x2E] = make_instruction(0x2E,opcode::ROL, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x3E] = make_instruction(0x3E,opcode::ROL, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0x6A] = make_instruction(0x6A,opcode::ROR, addressing_mode::Accum, 1, 2, 0);
    instr_tbl[0x66] = make_instruction(0x66,opcode::ROR, addressing_mode::ZP,    2, 5, 0);
    instr_tbl[0x76] = make_instruction(0x76,opcode::ROR, addressing_mode::ZPX,   2, 6, 0);
    instr_tbl[0x6E] = make_instruction(0x6E,opcode::ROR, addressing_mode::ABS,   3, 6, 0);
    instr_tbl[0x7E] = make_instruction(0x7E,opcode::ROR, addressing_mode::ABSX,  3, 7, 0);

    instr_tbl[0x40] = make_instruction(0x40,opcode::RTI, addressing_mode::Impl,  1, 6, 0);
    instr_tbl[0x60] = make_instruction(0x60,opcode::RTS, addressing_mode::Impl,  1, 6, 0);

    instr_tbl[0xE9] = make_instruction(0xE9,opcode::SBC, addressing_mode::IMM,   2, 2, 0);
    instr_tbl[0xE5] = make_instruction(0xE5,opcode::SBC, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0xF5] = make_instruction(0xF5,opcode::SBC, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0xED] = make_instruction(0xED,opcode::SBC, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0xFD] = make_instruction(0xFD,opcode::SBC, addressing_mode::ABSX,  3, 4, 1);
    instr_tbl[0xF9] = make_instruction(0xF9,opcode::SBC, addressing_mode::ABSY,  3, 4, 1);
    instr_tbl[0xE1] = make_instruction(0xE1,opcode::SBC, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0xF1] = make_instruction(0xF1,opcode::SBC, addressing_mode::INDY,  2, 5, 1);

    instr_tbl[0x38] = make_instruction(0x38,opcode::SEC, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xF8] = make_instruction(0xF8,opcode::SED, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x78] = make_instruction(0x78,opcode::SEI, addressing_mode::Impl,  1, 2, 0);

    instr_tbl[0x85] = make_instruction(0x85,opcode::STA, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x95] = make_instruction(0x95,opcode::STA, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x8D] = make_instruction(0x8D,opcode::STA, addressing_mode::ABS,   3, 4, 0);
    instr_tbl[0x9D] = make_instruction(0x9D,opcode::STA, addressing_mode::ABSX,  3, 5, 0);
    instr_tbl[0x99] = make_instruction(0x99,opcode::STA, addressing_mode::ABSY,  3, 5, 0);
    instr_tbl[0x81] = make_instruction(0x81,opcode::STA, addressing_mode::INDX,  2, 6, 0);
    instr_tbl[0x91] = make_instruction(0x91,opcode::STA, addressing_mode::INDY,  2, 6, 0);

    instr_tbl[0x86] = make_instruction(0x86,opcode::STX, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x96] = make_instruction(0x96,opcode::STX, addressing_mode::ZPY,   2, 4, 0);
    instr_tbl[0x8E] = make_instruction(0x8E,opcode::STX, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0x84] = make_instruction(0x84,opcode::STY, addressing_mode::ZP,    2, 3, 0);
    instr_tbl[0x94] = make_instruction(0x94,opcode::STY, addressing_mode::ZPX,   2, 4, 0);
    instr_tbl[0x8C] = make_instruction(0x8C,opcode::STY, addressing_mode::ABS,   3, 4, 0);

    instr_tbl[0xAA] = make_instruction(0xAA,opcode::TAX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xA8] = make_instruction(0xA8,opcode::TAY, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0xBA] = make_instruction(0xBA,opcode::TSX, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x8A] = make_instruction(0x8A,opcode::TXA, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x9A] = make_instruction(0x9A,opcode::TXS, addressing_mode::Impl,  1, 2, 0);
    instr_tbl[0x98] = make_instruction(0x98,opcode::TYA, addressing_mode::Impl,  1, 2, 0);


     
// ---------------- UNKNOWN/ILLEGAL OPCODES
     
//     instr_tbl[0x02] = make_instruction(0x02,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x03] = make_instruction(0x03,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x04] = make_instruction(0x04,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x07] = make_instruction(0x07,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x0B] = make_instruction(0x0B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x0C] = make_instruction(0x0C,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x0F] = make_instruction(0x0F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x12] = make_instruction(0x12,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x13] = make_instruction(0x13,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x14] = make_instruction(0x14,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x17] = make_instruction(0x17,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x1A] = make_instruction(0x1A,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x1B] = make_instruction(0x1B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x1C] = make_instruction(0x1C,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x1F] = make_instruction(0x1F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x22] = make_instruction(0x22,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x23] = make_instruction(0x23,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x27] = make_instruction(0x27,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x2B] = make_instruction(0x2B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x2F] = make_instruction(0x2F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x32] = make_instruction(0x32,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x33] = make_instruction(0x33,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x34] = make_instruction(0x34,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x37] = make_instruction(0x37,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x3A] = make_instruction(0x3A,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x3B] = make_instruction(0x3B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x3C] = make_instruction(0x3C,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x3F] = make_instruction(0x3F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x42] = make_instruction(0x42,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x43] = make_instruction(0x43,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x44] = make_instruction(0x44,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x47] = make_instruction(0x47,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x4B] = make_instruction(0x4B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x4F] = make_instruction(0x4F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x52] = make_instruction(0x52,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x53] = make_instruction(0x53,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x54] = make_instruction(0x54,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x57] = make_instruction(0x57,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x5A] = make_instruction(0x5A,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x5B] = make_instruction(0x5B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x5C] = make_instruction(0x5C,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x5F] = make_instruction(0x5F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x62] = make_instruction(0x62,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x63] = make_instruction(0x63,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x64] = make_instruction(0x64,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x67] = make_instruction(0x67,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x6B] = make_instruction(0x6B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x6F] = make_instruction(0x6F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x72] = make_instruction(0x72,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x73] = make_instruction(0x73,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x74] = make_instruction(0x74,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x77] = make_instruction(0x77,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x7A] = make_instruction(0x7A,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x7B] = make_instruction(0x7B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x7C] = make_instruction(0x7C,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x7F] = make_instruction(0x7F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x80] = make_instruction(0x80,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x82] = make_instruction(0x82,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x83] = make_instruction(0x83,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x87] = make_instruction(0x87,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x89] = make_instruction(0x89,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x8B] = make_instruction(0x8B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x8F] = make_instruction(0x8F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x92] = make_instruction(0x92,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x93] = make_instruction(0x93,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x97] = make_instruction(0x97,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x9B] = make_instruction(0x9B,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x9C] = make_instruction(0x9C,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x9E] = make_instruction(0x9E,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0x9F] = make_instruction(0x9F,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xA3] = make_instruction(0xA3,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xA7] = make_instruction(0xA7,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xAB] = make_instruction(0xAB,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xAF] = make_instruction(0xAF,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xB2] = make_instruction(0xB2,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xB3] = make_instruction(0xB3,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xB7] = make_instruction(0xB7,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xBB] = make_instruction(0xBB,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xBF] = make_instruction(0xBF,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xC2] = make_instruction(0xC2,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xC3] = make_instruction(0xC3,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xC7] = make_instruction(0xC7,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xCB] = make_instruction(0xCB,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xCF] = make_instruction(0xCF,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xD2] = make_instruction(0xD2,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xD3] = make_instruction(0xD3,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xD4] = make_instruction(0xD4,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xD7] = make_instruction(0xD7,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xDA] = make_instruction(0xDA,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xDB] = make_instruction(0xDB,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xDC] = make_instruction(0xDC,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xDF] = make_instruction(0xDF,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xE2] = make_instruction(0xE2,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xE3] = make_instruction(0xE3,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xE7] = make_instruction(0xE7,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xEB] = make_instruction(0xEB,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xF2] = make_instruction(0xF2,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xF3] = make_instruction(0xF3,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xF4] = make_instruction(0xF4,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xF7] = make_instruction(0xF7,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xFA] = make_instruction(0xFA,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xFB] = make_instruction(0xFB,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xFC] = make_instruction(0xFC,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xFE] = make_instruction(0xFE,opcode::None, addr_mode::None,   -1, -1);
//     instr_tbl[0xFF] = make_instruction(0xFF,opcode::None, addr_mode::None,   -1, -1);
  }
}
