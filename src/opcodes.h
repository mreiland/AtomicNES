#ifndef ATOM_NES_OPCODES_H
#define ATOM_NES_OPCODES_H

#include <string>

enum class opcode {
  None = 0,
  ADC, AND, ASL, BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC, BVS, CLC,
  CLD, CLI, CLV, CMP, CPX, CPY, DEC, DEX, DEY, EOR, INC, INX, INY, JMP,
  JSR, LDA, LDX, LDY, LSR, NOP, ORA, PHA, PHP, PLA, PLP, ROL, ROR, RTI,
  RTS, SBC, SEC, SED, SEI, STA, STX, STY, TAX, TAY, TSX, TXA, TXS, TYA
};

inline std::string OPC2string(opcode opc) {
  switch(opc) {
    case opcode::ADC: return "ADC";
    case opcode::AND: return "AND";
    case opcode::ASL: return "ASL";
    case opcode::BCC: return "BCC";
    case opcode::BCS: return "BCS";
    case opcode::BEQ: return "BEQ";
    case opcode::BIT: return "BIT";
    case opcode::BMI: return "BMI";
    case opcode::BNE: return "BNE";
    case opcode::BPL: return "BPL";
    case opcode::BRK: return "BRK";
    case opcode::BVC: return "BVC";
    case opcode::BVS: return "BVS";
    case opcode::CLC: return "CLC";
    case opcode::CLD: return "CLD";
    case opcode::CLI: return "CLI";
    case opcode::CLV: return "CLV";
    case opcode::CMP: return "CMP";
    case opcode::CPX: return "CPX";
    case opcode::CPY: return "CPY";
    case opcode::DEC: return "DEC";
    case opcode::DEX: return "DEX";
    case opcode::DEY: return "DEY";
    case opcode::EOR: return "EOR";
    case opcode::INC: return "INC";
    case opcode::INX: return "INX";
    case opcode::INY: return "INY";
    case opcode::JMP: return "JMP";
    case opcode::JSR: return "JSR";
    case opcode::LDA: return "LDA";
    case opcode::LDX: return "LDX";
    case opcode::LDY: return "LDY";
    case opcode::LSR: return "LSR";
    case opcode::NOP: return "NOP";
    case opcode::ORA: return "ORA";
    case opcode::PHA: return "PHA";
    case opcode::PHP: return "PHP";
    case opcode::PLA: return "PLA";
    case opcode::PLP: return "PLP";
    case opcode::ROL: return "ROL";
    case opcode::ROR: return "ROR";
    case opcode::RTI: return "RTI";
    case opcode::RTS: return "RTS";
    case opcode::SBC: return "SBC";
    case opcode::SEC: return "SEC";
    case opcode::SED: return "SED";
    case opcode::SEI: return "SEI";
    case opcode::STA: return "STA";
    case opcode::STX: return "STX";
    case opcode::STY: return "STY";
    case opcode::TAX: return "TAX";
    case opcode::TAY: return "TAY";
    case opcode::TSX: return "TSX";
    case opcode::TXA: return "TXA";
    case opcode::TXS: return "TXS";
    case opcode::TYA: return "TYA";
  };
  return "";
}

inline opcode string2OPC(std::string str) {
  if(str == "ADC") return opcode::ADC;
  if(str == "AND") return opcode::AND;
  if(str == "ASL") return opcode::ASL;
  if(str == "BCC") return opcode::BCC;
  if(str == "BCS") return opcode::BCS;
  if(str == "BEQ") return opcode::BEQ;
  if(str == "BIT") return opcode::BIT;
  if(str == "BMI") return opcode::BMI;
  if(str == "BNE") return opcode::BNE;
  if(str == "BPL") return opcode::BPL;
  if(str == "BRK") return opcode::BRK;
  if(str == "BVC") return opcode::BVC;
  if(str == "BVS") return opcode::BVS;
  if(str == "CLC") return opcode::CLC;
  if(str == "CLD") return opcode::CLD;
  if(str == "CLI") return opcode::CLI;
  if(str == "CLV") return opcode::CLV;
  if(str == "CMP") return opcode::CMP;
  if(str == "CPX") return opcode::CPX;
  if(str == "CPY") return opcode::CPY;
  if(str == "DEC") return opcode::DEC;
  if(str == "DEX") return opcode::DEX;
  if(str == "DEY") return opcode::DEY;
  if(str == "EOR") return opcode::EOR;
  if(str == "INC") return opcode::INC;
  if(str == "INX") return opcode::INX;
  if(str == "INY") return opcode::INY;
  if(str == "JMP") return opcode::JMP;
  if(str == "JSR") return opcode::JSR;
  if(str == "LDA") return opcode::LDA;
  if(str == "LDX") return opcode::LDX;
  if(str == "LDY") return opcode::LDY;
  if(str == "LSR") return opcode::LSR;
  if(str == "NOP") return opcode::NOP;
  if(str == "ORA") return opcode::ORA;
  if(str == "PHA") return opcode::PHA;
  if(str == "PHP") return opcode::PHP;
  if(str == "PLA") return opcode::PLA;
  if(str == "PLP") return opcode::PLP;
  if(str == "ROL") return opcode::ROL;
  if(str == "ROR") return opcode::ROR;
  if(str == "RTI") return opcode::RTI;
  if(str == "RTS") return opcode::RTS;
  if(str == "SBC") return opcode::SBC;
  if(str == "SEC") return opcode::SEC;
  if(str == "SED") return opcode::SED;
  if(str == "SEI") return opcode::SEI;
  if(str == "STA") return opcode::STA;
  if(str == "STX") return opcode::STX;
  if(str == "STY") return opcode::STY;
  if(str == "TAX") return opcode::TAX;
  if(str == "TAY") return opcode::TAY;
  if(str == "TSX") return opcode::TSX;
  if(str == "TXA") return opcode::TXA;
  if(str == "TXS") return opcode::TXS;
  if(str == "TYA") return opcode::TYA;
  
  return opcode::None;
}




#endif
