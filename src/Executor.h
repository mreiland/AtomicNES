#ifndef ATOM_NES_EXECUTOR_H
#define ATOM_NES_EXECUTOR_H

#include "Cpu.h"
#include "DecodeInfo.h"
#include "Memory.h"

namespace Executor {
  void restart(Cpu *, Memory *);
  void power_on(Cpu *, Memory *);
  
  DecodeInfo fetch_and_decode(Cpu *, Memory *);
  void execute(Cpu *, Memory *, DecodeInfo);
}

#endif
