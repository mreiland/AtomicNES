#ifndef ATOMIC_NES_INSTRUCTION_H
#define ATOMIC_NES_INSTRUCTION_H

#include "AddressingMode.h"
#include "Operation.h"

struct Instruction {
  uint8_t opcode;
  
  Operation operation;
  AddressingMode mode;
  
  uint8_t len;
  uint8_t cycles;
  uint8_t page_cycles; // number of additional pages if page boundary crossed.
};

Instruction *get_instruction(int opcode_value);
void initialize_instructions();

#endif
