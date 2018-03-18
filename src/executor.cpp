#include "executor.h"

namespace executor {
  void restart(cpu *cpu, memory *mem) {
  }
  void power_on(cpu *cpu, memory *mem) {
  }
  
  // decode_info will need to carry the instruction around with it, should just use a pointer
  // to the actual instruction to minimize copying
  //
  decode_info fetch_and_decode(cpu *cpu, memory *men) {
    decode_info info;
    
    // examine memory, use stack pointer to grab next opcode
    // use opcode to grab instruction
    // use instruction to determine addressing mode
    // use addressing mode to fill decode_info
    
    return info;
  }
  void execute(cpu *cpu, memory *mem, decode_info decoded) {
  }
}
