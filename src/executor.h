#ifndef ATOM_NES_EXECUTOR_H
#define ATOM_NES_EXECUTOR_H

#include "Cpu.h"
#include "DecodeInfo.h"
#include "memory.h"

namespace executor {
  void restart(Cpu *, memory *);
  void power_on(Cpu *, memory *);
  
  DecodeInfo fetch_and_decode(Cpu *, memory *);
  void execute(Cpu *, memory *, DecodeInfo);
}

#endif
