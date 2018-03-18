#ifndef ATOM_NES_INSTRUCTIONS_H
#define ATOM_NES_INSTRUCTIONS_H

#include "Instruction.h"

namespace instructions {
  Instruction *get_instruction(int opcode_value);
  void initialize();
}

#endif
