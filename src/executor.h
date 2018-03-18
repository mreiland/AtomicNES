#ifndef ATOM_NES_EXECUTOR_H
#define ATOM_NES_EXECUTOR_H

#include "cpu.h"
#include "decode_info.h"
#include "memory.h"

namespace executor {
  void restart(cpu *, memory *);
  void power_on(cpu *, memory *);
  
  decode_info fetch_and_decode(cpu *, memory *);
  void execute(cpu *, memory *, decode_info);
}

#endif
