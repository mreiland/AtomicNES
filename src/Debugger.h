#ifndef ATOMIC_NES_DEBUGGER_H
#define ATOMIC_NES_DEBUGGER_H

#include "Cpu.h"
#include "DecodeInfo.h"
#include "Memory.h"

#include <vector>

class Debugger {
public:
  struct DebuggerFrame {
    Cpu cpu;
    Memory mem;
    DecodeInfo decoded;
  };

public:
  Debugger();
  void set_pc_breakpoint(uint16_t);
  uint16_t get_pc_breakpoint();
  void debug(Cpu *, Memory *, const DecodeInfo &);
private:
  uint16_t pc_breakpoint = 0;
  bool is_debugging = false;
  const int max_frames = 20;

  std::vector<DebuggerFrame> frames;
  std::vector<DebuggerFrame>::iterator frame_iter;

  void time_machine_debug(Cpu *, Memory *, const DecodeInfo &);
};

#endif

