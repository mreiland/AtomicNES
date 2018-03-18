#ifndef ATOM_NES_INSTRUCTION_H
#define ATOM_NES_INSTRUCTION_H

#include "addressing_mode.h"
#include "operation.h"

struct Instruction {
  uint8_t opcode;
  
  operation opcode_type;
  addressing_mode addr_mode_type;
  
  uint8_t len;
  uint8_t cycles;
  uint8_t page_cycles; // number of additional pages if page boundary crossed.
};

#endif
