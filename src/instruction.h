#ifndef ATOM_NES_INSTRUCTION_H
#define ATOM_NES_INSTRUCTION_H

#include "addressing_modes.h"
#include "opcodes.h"

struct Instruction {
  int opcode_value;
  
  opcode opcode_class;
  addr_mode addr_mode_class;
  
  int len;
  int cycles;
  int page_cycles; // number of additional pages if page boundary crossed.
};

#endif
