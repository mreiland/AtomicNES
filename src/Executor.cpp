#include "Executor.h"

namespace Executor {
  void reset(Cpu *cpu, Memory *mem) {
    cpu->PC = mem->read16(0xFFFD);
    cpu->SP = 0xFD;
    cpu->set_flags(0x24);
  }
  void power_on(Cpu *cpu, Memory *mem) {
    reset(cpu,mem);
  }
  
  // decode_info will need to carry the instruction around with it, should just use a pointer
  // to the actual instruction to minimize copying
  //
  DecodeInfo fetch_and_decode(Cpu *cpu, Memory *men) {
    DecodeInfo info;
    
    // examine memory, use stack pointer to grab next operation
    // use operation to grab instruction
    // use instruction to determine addressing mode
    // use addressing mode to fill decode_info
    
    return info;
  }
  void execute(Cpu *cpu, Memory *mem, DecodeInfo decoded) {
  }
}
