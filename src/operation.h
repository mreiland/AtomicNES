#ifndef ATOM_NES_OPCODES_H
#define ATOM_NES_OPCODES_H

#include <string>

enum class operation {
  None = 0,
  ADC, AND, ASL, BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC, BVS, CLC,
  CLD, CLI, CLV, CMP, CPX, CPY, DEC, DEX, DEY, EOR, INC, INX, INY, JMP,
  JSR, LDA, LDX, LDY, LSR, NOP, ORA, PHA, PHP, PLA, PLP, ROL, ROR, RTI,
  RTS, SBC, SEC, SED, SEI, STA, STX, STY, TAX, TAY, TSX, TXA, TXS, TYA
};

inline std::string to_string(operation opc) {
  switch(opc) {
    case operation::ADC: return "ADC";
    case operation::AND: return "AND";
    case operation::ASL: return "ASL";
    case operation::BCC: return "BCC";
    case operation::BCS: return "BCS";
    case operation::BEQ: return "BEQ";
    case operation::BIT: return "BIT";
    case operation::BMI: return "BMI";
    case operation::BNE: return "BNE";
    case operation::BPL: return "BPL";
    case operation::BRK: return "BRK";
    case operation::BVC: return "BVC";
    case operation::BVS: return "BVS";
    case operation::CLC: return "CLC";
    case operation::CLD: return "CLD";
    case operation::CLI: return "CLI";
    case operation::CLV: return "CLV";
    case operation::CMP: return "CMP";
    case operation::CPX: return "CPX";
    case operation::CPY: return "CPY";
    case operation::DEC: return "DEC";
    case operation::DEX: return "DEX";
    case operation::DEY: return "DEY";
    case operation::EOR: return "EOR";
    case operation::INC: return "INC";
    case operation::INX: return "INX";
    case operation::INY: return "INY";
    case operation::JMP: return "JMP";
    case operation::JSR: return "JSR";
    case operation::LDA: return "LDA";
    case operation::LDX: return "LDX";
    case operation::LDY: return "LDY";
    case operation::LSR: return "LSR";
    case operation::NOP: return "NOP";
    case operation::ORA: return "ORA";
    case operation::PHA: return "PHA";
    case operation::PHP: return "PHP";
    case operation::PLA: return "PLA";
    case operation::PLP: return "PLP";
    case operation::ROL: return "ROL";
    case operation::ROR: return "ROR";
    case operation::RTI: return "RTI";
    case operation::RTS: return "RTS";
    case operation::SBC: return "SBC";
    case operation::SEC: return "SEC";
    case operation::SED: return "SED";
    case operation::SEI: return "SEI";
    case operation::STA: return "STA";
    case operation::STX: return "STX";
    case operation::STY: return "STY";
    case operation::TAX: return "TAX";
    case operation::TAY: return "TAY";
    case operation::TSX: return "TSX";
    case operation::TXA: return "TXA";
    case operation::TXS: return "TXS";
    case operation::TYA: return "TYA";
  };
  return "";
}

inline operation to_operation(std::string str) {
  if(str == "ADC") return operation::ADC;
  if(str == "AND") return operation::AND;
  if(str == "ASL") return operation::ASL;
  if(str == "BCC") return operation::BCC;
  if(str == "BCS") return operation::BCS;
  if(str == "BEQ") return operation::BEQ;
  if(str == "BIT") return operation::BIT;
  if(str == "BMI") return operation::BMI;
  if(str == "BNE") return operation::BNE;
  if(str == "BPL") return operation::BPL;
  if(str == "BRK") return operation::BRK;
  if(str == "BVC") return operation::BVC;
  if(str == "BVS") return operation::BVS;
  if(str == "CLC") return operation::CLC;
  if(str == "CLD") return operation::CLD;
  if(str == "CLI") return operation::CLI;
  if(str == "CLV") return operation::CLV;
  if(str == "CMP") return operation::CMP;
  if(str == "CPX") return operation::CPX;
  if(str == "CPY") return operation::CPY;
  if(str == "DEC") return operation::DEC;
  if(str == "DEX") return operation::DEX;
  if(str == "DEY") return operation::DEY;
  if(str == "EOR") return operation::EOR;
  if(str == "INC") return operation::INC;
  if(str == "INX") return operation::INX;
  if(str == "INY") return operation::INY;
  if(str == "JMP") return operation::JMP;
  if(str == "JSR") return operation::JSR;
  if(str == "LDA") return operation::LDA;
  if(str == "LDX") return operation::LDX;
  if(str == "LDY") return operation::LDY;
  if(str == "LSR") return operation::LSR;
  if(str == "NOP") return operation::NOP;
  if(str == "ORA") return operation::ORA;
  if(str == "PHA") return operation::PHA;
  if(str == "PHP") return operation::PHP;
  if(str == "PLA") return operation::PLA;
  if(str == "PLP") return operation::PLP;
  if(str == "ROL") return operation::ROL;
  if(str == "ROR") return operation::ROR;
  if(str == "RTI") return operation::RTI;
  if(str == "RTS") return operation::RTS;
  if(str == "SBC") return operation::SBC;
  if(str == "SEC") return operation::SEC;
  if(str == "SED") return operation::SED;
  if(str == "SEI") return operation::SEI;
  if(str == "STA") return operation::STA;
  if(str == "STX") return operation::STX;
  if(str == "STY") return operation::STY;
  if(str == "TAX") return operation::TAX;
  if(str == "TAY") return operation::TAY;
  if(str == "TSX") return operation::TSX;
  if(str == "TXA") return operation::TXA;
  if(str == "TXS") return operation::TXS;
  if(str == "TYA") return operation::TYA;
  
  return operation::None;
}




#endif
