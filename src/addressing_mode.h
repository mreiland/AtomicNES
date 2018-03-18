#ifndef ATOM_NES_ADDRESSING_MODES_H
#define ATOM_NES_ADDRESSING_MODES_H

#include <string>

enum class addressing_mode {
  None = 0,
  Accum, IMM, Impl, Rel, ZP, ZPX, ZPY,
  ABS, ABSX, ABSY, IND, INDX, INDY
};

inline std::string to_string(addressing_mode adm) {
  switch(adm) {
    case addressing_mode::Accum: return "Accumulator";
    case addressing_mode::IMM:   return "Immediate";
    case addressing_mode::Impl:  return "Implied";
    case addressing_mode::Rel:   return "Relative";
    case addressing_mode::ZP:    return "ZP";
    case addressing_mode::ZPX:   return "ZPX";
    case addressing_mode::ZPY:   return "ZPY";
    case addressing_mode::ABS:   return "ABS";
    case addressing_mode::ABSX:  return "ABSX";
    case addressing_mode::ABSY:  return "ABSY";
    case addressing_mode::IND:   return "IND";
    case addressing_mode::INDX:  return "INDX";
    case addressing_mode::INDY:  return "INDY";
  };
  return "";
}

inline addressing_mode to_addressing_mode(std::string str) {
  if(str == "Accumulator") return addressing_mode::Accum;
  if(str == "Immediate")   return addressing_mode::IMM;
  if(str == "Implied")     return addressing_mode::Impl;
  if(str == "Relative")    return addressing_mode::Rel;
  if(str == "ZP")          return addressing_mode::ZP;
  if(str == "ZPX")         return addressing_mode::ZPX;
  if(str == "ZPY")         return addressing_mode::ZPY;
  if(str == "ABS")         return addressing_mode::ABS;
  if(str == "ABSX")        return addressing_mode::ZPX;
  if(str == "ABSY")        return addressing_mode::ABSY;
  if(str == "IND")         return addressing_mode::IND;
  if(str == "INDX")        return addressing_mode::INDX;
  if(str == "INDY")        return addressing_mode::INDY;
  return addressing_mode::None;
}




#endif
