#ifndef ATOMIC_NES_OPCODES_H
#define ATOMIC_NES_OPCODES_H

#include <string>

enum class Operation {
  None = 0,
  ADC, AND, ASL, BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC, BVS, CLC,
  CLD, CLI, CLV, CMP, CPX, CPY, DEC, DEX, DEY, EOR, INC, INX, INY, JMP,
  JSR, LDA, LDX, LDY, LSR, NOP, ORA, PHA, PHP, PLA, PLP, ROL, ROR, RTI,
  RTS, SBC, SEC, SED, SEI, STA, STX, STY, TAX, TAY, TSX, TXA, TXS, TYA
};

inline std::string to_string(Operation opc) {
  switch(opc) {
    case Operation::ADC: return "ADC";
    case Operation::AND: return "AND";
    case Operation::ASL: return "ASL";
    case Operation::BCC: return "BCC";
    case Operation::BCS: return "BCS";
    case Operation::BEQ: return "BEQ";
    case Operation::BIT: return "BIT";
    case Operation::BMI: return "BMI";
    case Operation::BNE: return "BNE";
    case Operation::BPL: return "BPL";
    case Operation::BRK: return "BRK";
    case Operation::BVC: return "BVC";
    case Operation::BVS: return "BVS";
    case Operation::CLC: return "CLC";
    case Operation::CLD: return "CLD";
    case Operation::CLI: return "CLI";
    case Operation::CLV: return "CLV";
    case Operation::CMP: return "CMP";
    case Operation::CPX: return "CPX";
    case Operation::CPY: return "CPY";
    case Operation::DEC: return "DEC";
    case Operation::DEX: return "DEX";
    case Operation::DEY: return "DEY";
    case Operation::EOR: return "EOR";
    case Operation::INC: return "INC";
    case Operation::INX: return "INX";
    case Operation::INY: return "INY";
    case Operation::JMP: return "JMP";
    case Operation::JSR: return "JSR";
    case Operation::LDA: return "LDA";
    case Operation::LDX: return "LDX";
    case Operation::LDY: return "LDY";
    case Operation::LSR: return "LSR";
    case Operation::NOP: return "NOP";
    case Operation::ORA: return "ORA";
    case Operation::PHA: return "PHA";
    case Operation::PHP: return "PHP";
    case Operation::PLA: return "PLA";
    case Operation::PLP: return "PLP";
    case Operation::ROL: return "ROL";
    case Operation::ROR: return "ROR";
    case Operation::RTI: return "RTI";
    case Operation::RTS: return "RTS";
    case Operation::SBC: return "SBC";
    case Operation::SEC: return "SEC";
    case Operation::SED: return "SED";
    case Operation::SEI: return "SEI";
    case Operation::STA: return "STA";
    case Operation::STX: return "STX";
    case Operation::STY: return "STY";
    case Operation::TAX: return "TAX";
    case Operation::TAY: return "TAY";
    case Operation::TSX: return "TSX";
    case Operation::TXA: return "TXA";
    case Operation::TXS: return "TXS";
    case Operation::TYA: return "TYA";
  };
  return "";
}

inline Operation to_operation(std::string str) {
  if(str == "ADC") return Operation::ADC;
  if(str == "AND") return Operation::AND;
  if(str == "ASL") return Operation::ASL;
  if(str == "BCC") return Operation::BCC;
  if(str == "BCS") return Operation::BCS;
  if(str == "BEQ") return Operation::BEQ;
  if(str == "BIT") return Operation::BIT;
  if(str == "BMI") return Operation::BMI;
  if(str == "BNE") return Operation::BNE;
  if(str == "BPL") return Operation::BPL;
  if(str == "BRK") return Operation::BRK;
  if(str == "BVC") return Operation::BVC;
  if(str == "BVS") return Operation::BVS;
  if(str == "CLC") return Operation::CLC;
  if(str == "CLD") return Operation::CLD;
  if(str == "CLI") return Operation::CLI;
  if(str == "CLV") return Operation::CLV;
  if(str == "CMP") return Operation::CMP;
  if(str == "CPX") return Operation::CPX;
  if(str == "CPY") return Operation::CPY;
  if(str == "DEC") return Operation::DEC;
  if(str == "DEX") return Operation::DEX;
  if(str == "DEY") return Operation::DEY;
  if(str == "EOR") return Operation::EOR;
  if(str == "INC") return Operation::INC;
  if(str == "INX") return Operation::INX;
  if(str == "INY") return Operation::INY;
  if(str == "JMP") return Operation::JMP;
  if(str == "JSR") return Operation::JSR;
  if(str == "LDA") return Operation::LDA;
  if(str == "LDX") return Operation::LDX;
  if(str == "LDY") return Operation::LDY;
  if(str == "LSR") return Operation::LSR;
  if(str == "NOP") return Operation::NOP;
  if(str == "ORA") return Operation::ORA;
  if(str == "PHA") return Operation::PHA;
  if(str == "PHP") return Operation::PHP;
  if(str == "PLA") return Operation::PLA;
  if(str == "PLP") return Operation::PLP;
  if(str == "ROL") return Operation::ROL;
  if(str == "ROR") return Operation::ROR;
  if(str == "RTI") return Operation::RTI;
  if(str == "RTS") return Operation::RTS;
  if(str == "SBC") return Operation::SBC;
  if(str == "SEC") return Operation::SEC;
  if(str == "SED") return Operation::SED;
  if(str == "SEI") return Operation::SEI;
  if(str == "STA") return Operation::STA;
  if(str == "STX") return Operation::STX;
  if(str == "STY") return Operation::STY;
  if(str == "TAX") return Operation::TAX;
  if(str == "TAY") return Operation::TAY;
  if(str == "TSX") return Operation::TSX;
  if(str == "TXA") return Operation::TXA;
  if(str == "TXS") return Operation::TXS;
  if(str == "TYA") return Operation::TYA;
  
  return Operation::None;
}




#endif
