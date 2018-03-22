#ifndef ATOMIC_NES_ADDRESSING_MODES_H
#define ATOMIC_NES_ADDRESSING_MODES_H

#include <string>

enum class AddressingMode {
  None = 0,
  Accum, IMM, Impl, Rel, ZP, ZPX, ZPY,
  ABS, ABSX, ABSY, IND, INDX, INDY
};

inline std::string to_string(AddressingMode adm) {
  switch(adm) {
    case AddressingMode::Accum: return "Accumulator";
    case AddressingMode::IMM:   return "Immediate";
    case AddressingMode::Impl:  return "Implied";
    case AddressingMode::Rel:   return "Relative";
    case AddressingMode::ZP:    return "ZP";
    case AddressingMode::ZPX:   return "ZPX";
    case AddressingMode::ZPY:   return "ZPY";
    case AddressingMode::ABS:   return "ABS";
    case AddressingMode::ABSX:  return "ABSX";
    case AddressingMode::ABSY:  return "ABSY";
    case AddressingMode::IND:   return "IND";
    case AddressingMode::INDX:  return "INDX";
    case AddressingMode::INDY:  return "INDY";
  };
  return "";
}

inline AddressingMode to_addressing_mode(std::string str) {
  if(str == "Accumulator") return AddressingMode::Accum;
  if(str == "Immediate")   return AddressingMode::IMM;
  if(str == "Implied")     return AddressingMode::Impl;
  if(str == "Relative")    return AddressingMode::Rel;
  if(str == "ZP")          return AddressingMode::ZP;
  if(str == "ZPX")         return AddressingMode::ZPX;
  if(str == "ZPY")         return AddressingMode::ZPY;
  if(str == "ABS")         return AddressingMode::ABS;
  if(str == "ABSX")        return AddressingMode::ZPX;
  if(str == "ABSY")        return AddressingMode::ABSY;
  if(str == "IND")         return AddressingMode::IND;
  if(str == "INDX")        return AddressingMode::INDX;
  if(str == "INDY")        return AddressingMode::INDY;
  return AddressingMode::None;
}




#endif
