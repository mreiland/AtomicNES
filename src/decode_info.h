#ifndef ATOM_NES_DECODE_INFO_H
#define ATOM_NES_DECODE_INFO_H

#include "Operation.h"
#include "addressing_mode.h"
#include "instruction.h"

struct decode_info {
  Instruction *instruction;
  
  uint16_t addr1;
  uint16_t addr2;
  uint16_t addr3;
  
  uint8_t val1;
  uint8_t val2;
  uint8_t val3;
};

#endif
