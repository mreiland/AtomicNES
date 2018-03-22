#ifndef ATOM_NES_EXECUTOR_H
#define ATOM_NES_EXECUTOR_H

#include "Cpu.h"
#include "DecodeInfo.h"
#include "Memory.h"

namespace Executor {
  void reset(Cpu *, Memory *);
  void power_on(Cpu *, Memory *);
  
  void fetch_and_decode(const Cpu &, const Memory &, DecodeInfo *);
  void execute(Cpu *, Memory *, const DecodeInfo &);
}

#endif
