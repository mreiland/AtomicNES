#ifndef ATOM_NES_ADDRESSING_MODES_H
#define ATOM_NES_ADDRESSING_MODES_H

#include <string>

enum class addr_mode {
  None = 0,
  Accum, IMM, Impl, Rel, ZP, ZPX, ZPY,
  ABS, ABSX, ABSY, IND, INDX, INDY
};

inline std::string addr_mode2string(addr_mode adm) {
  switch(adm) {
    case addr_mode::Accum: return "Accumulator";
    case addr_mode::IMM:   return "Immediate";
    case addr_mode::Impl:  return "Implied";
    case addr_mode::Rel:   return "Relative";
    case addr_mode::ZP:    return "ZP";
    case addr_mode::ZPX:   return "ZPX";
    case addr_mode::ZPY:   return "ZPY";
    case addr_mode::ABS:   return "ABS";
    case addr_mode::ABSX:  return "ABSX";
    case addr_mode::ABSY:  return "ABSY";
    case addr_mode::IND:   return "IND";
    case addr_mode::INDX:  return "INDX";
    case addr_mode::INDY:  return "INDY";
  };
  return "";
}

inline addr_mode string2addr_mode(std::string str) {
  if(str == "Accumulator") return addr_mode::Accum;
  if(str == "Immediate")   return addr_mode::IMM;
  if(str == "Implied")     return addr_mode::Impl;
  if(str == "Relative")    return addr_mode::Rel;
  if(str == "ZP")          return addr_mode::ZP;
  if(str == "ZPX")         return addr_mode::ZPX;
  if(str == "ZPY")         return addr_mode::ZPY;
  if(str == "ABS")         return addr_mode::ABS;
  if(str == "ABSX")        return addr_mode::ZPX;
  if(str == "ABSY")        return addr_mode::ABSY;
  if(str == "IND")         return addr_mode::IND;
  if(str == "INDX")        return addr_mode::INDX;
  if(str == "INDY")        return addr_mode::INDY;
  return addr_mode::None;
}




#endif
