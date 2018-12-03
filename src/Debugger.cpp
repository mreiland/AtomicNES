#include "Debugger.h"

#include "error/unimplemented_error.h"
#include "fmt/format.h"
#include "fmt/printf.h"

#include <iostream>
#include <string>

using DebuggerFrame = Debugger::DebuggerFrame;

namespace {
  enum class DbgCommands { None = 0, Run, StepForward, StepBack, DisplayContext, DisplayAllFrames };

  void display_all_frames(std::vector<DebuggerFrame> &frames, const std::string &prefix);
  void display_context(std::vector<DebuggerFrame>::iterator iter, const std::string prefix);
  void display_context(const Cpu &cpu, const Memory &mem, const DecodeInfo &decoded, std::string prefix = "");
  void display_menu();
  DbgCommands get_input();
  void push_frame(std::vector<DebuggerFrame> &frames, int max_frames, Cpu *cpu, Memory *mem, const DecodeInfo &decoded);
}

Debugger::Debugger() {
  this->frame_iter = this->frames.end();
}

void Debugger::set_pc_breakpoint(uint16_t val) {
  this->pc_breakpoint = val;
}
uint16_t Debugger::get_pc_breakpoint() {
  return this->pc_breakpoint;
}
void Debugger::debug(Cpu *cpu, Memory *mem, const DecodeInfo &decoded) {
  push_frame(this->frames, this->max_frames, cpu,mem,decoded);
  if(cpu->PC != this->pc_breakpoint && !this->is_debugging) return;

  this->is_debugging = true;
  this->frame_iter = this->frames.end();

  display_context(*cpu,*mem,decoded);
  auto cmd = DbgCommands::DisplayContext;

  while(cmd == DbgCommands::DisplayContext || cmd == DbgCommands::DisplayAllFrames) {
    cmd = get_input();
    switch(cmd) {
      case DbgCommands::DisplayContext:
        display_context(*cpu,*mem,decoded);
        fmt::print("\n\n");
        continue;
      case DbgCommands::Run:
        this->is_debugging = false;
        continue;
      case DbgCommands::StepBack:
        if(this->frames.empty()) fmt::print("No history to go back to");
        else                     this->time_machine_debug(cpu,mem,decoded);
        continue;
      case DbgCommands::StepForward:
        continue;
      case DbgCommands::DisplayAllFrames:
        display_all_frames(this->frames, "[ALL] ");
        continue;
    }
  }
}

void Debugger::time_machine_debug(Cpu *cpu, Memory *mem, const DecodeInfo &decoded) {
  std::string prefix = "[TM] ";
  auto cmd = DbgCommands::StepBack;
  // set to the last saved frame, the switch will decrement to the previous frame
  this->frame_iter = this->frames.end()-1;

  // break inside the switch will actually break the while loop so we instead use a goto and a label
  //
  while(!this->frames.empty() && this->frame_iter < this->frames.end()) {
    switch(cmd) {
      case DbgCommands::DisplayContext:
          goto BREAK_SWITCH;
      case DbgCommands::Run:
        this->frame_iter = this->frames.end();
        this->is_debugging = false;
        goto BREAK_SWITCH;
      case DbgCommands::StepBack:
        if(this->frames.empty() || this->frame_iter == this->frames.begin())
          fmt::print("Cannot step back any further");
        else
          this->frame_iter--;
        goto BREAK_SWITCH;
      case DbgCommands::StepForward:
        if(this->frame_iter < this->frames.end())
          this->frame_iter++;
        goto BREAK_SWITCH;
      case DbgCommands::DisplayAllFrames:
        display_all_frames(this->frames, prefix + "[ALL] ");
        goto BREAK_SWITCH;
    }
BREAK_SWITCH:

    if(!this->frames.empty() && this->frame_iter != this->frames.end()) {
      display_context(this->frame_iter,prefix);
      fmt::print("\n\n");
      cmd = get_input();
    }
  }
}


namespace {
  void display_all_frames(std::vector<DebuggerFrame> &frames, const std::string &prefix) {
    for(auto i = frames.begin(); i != frames.end(); ++i) {
      display_context(i,prefix);
    }
  }
  void display_context(std::vector<DebuggerFrame>::iterator iter, const std::string prefix) {
    display_context(iter->cpu,iter->mem,iter->decoded,prefix);
  }
  void display_context(const Cpu &cpu, const Memory &mem, const DecodeInfo &decoded, std::string prefix) {
    auto opc = mem.read8(cpu.PC);
    std::string byte2 = "   ";
    std::string byte3 = "   ";

    if(decoded.instruction->len > 1) byte2 = fmt::format("${:>02X}",mem.read8(cpu.PC+1));
    if(decoded.instruction->len > 2) byte3 = fmt::format("${:>02X}",mem.read8(cpu.PC+2));

    // current PC, SP, registers, bit pattern of processor flags
    fmt::print("{}---------------------------------------------------------------\n",prefix);
    fmt::print("{}PC    OPCODE     |               |  SP  A   X   Y   P  NVUBDIZC\n",prefix);
    fmt::print("{}${:>04X} ${:>02X} {} {}| {:^3} {:^10}| ${:>02X} ${:>02X} ${:>02X} ${:>02X} ${:>02X} ",
        prefix,
        cpu.PC, mem.read8(cpu.PC), byte2,byte3, to_string(decoded.instruction->operation),to_string(decoded.instruction->mode),
        cpu.SP, cpu.a, cpu.x, cpu.y, cpu.get_flags());
    fmt::print("{}{}{}{}{}{}{}{}\n", (int)cpu.N,(int)cpu.V,(int)cpu.U,(int)cpu.B,(int)cpu.D,(int)cpu.I,(int)cpu.Z,(int)cpu.C);
    fmt::print("{}- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n",prefix);
    fmt::print("{}", prefix);

    auto columns = 15;
    auto addr = 0xFF;

    while(addr > cpu.SP) {
      auto count = (addr - cpu.SP);
      if(count > columns)
        count = columns;

      for(auto i = 0; i <= count && addr-i > cpu.SP; ++i)
        fmt::print("${:>02X} ",addr-i);
      fmt::print("\n");
      for(auto i = 0; i <= count && addr-i > cpu.SP; ++i)
        fmt::print(" {:>02X} ", mem.read8(0x100 | uint16_t(addr-i)));
      fmt::print("\n\n");
      addr-=columns+1;
    }
    
    fmt::print("\n{}---------------------------------------------------------------\n",prefix);
  }

  void display_menu() {
    fmt::print("[l] step forward [h] step back [d] display context [a] display all frames [r] run");
  }

  DbgCommands get_input() {
    auto cmd = DbgCommands::None;

    while(cmd == DbgCommands::None) {
      display_menu();
      fmt::print("\n> ");
      char c = std::cin.get();

      if(c == 'l' || c == 'L') return DbgCommands::StepForward;
      if(c == 'h' || c == 'H') return DbgCommands::StepBack;
      if(c == 'd' || c == 'D') return DbgCommands::DisplayContext;
      if(c == 'r' || c == 'R') return DbgCommands::Run;
      if(c == 'a' || c == 'A') return DbgCommands::DisplayAllFrames;
    }
    return cmd;
  }

  void push_frame(
      std::vector<DebuggerFrame> &frames,
      int max_frames,
      Cpu *cpu,
      Memory *mem,
      const DecodeInfo &decoded)
  {
    DebuggerFrame f = {
      .cpu = *cpu,
      .mem = *mem,
      .decoded = decoded,
    };
    if(frames.size() >= max_frames)
      frames.erase(frames.begin());
    frames.push_back(f);
  }
}
