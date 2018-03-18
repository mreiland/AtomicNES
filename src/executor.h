#ifndef ATOM_NES_EXECUTOR_H
#define ATOM_NES_EXECUTOR_H

#include "Cpu.h"
#include "decode_info.h"
#include "memory.h"

namespace executor {
  void restart(Cpu *, memory *);
  void power_on(Cpu *, memory *);
  
  decode_info fetch_and_decode(Cpu *, memory *);
  void execute(Cpu *, memory *, decode_info);
}

#endif
