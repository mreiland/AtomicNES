#include <iostream>
#include <string>
#include <stdexcept>

#include "fmt/format.h"
#include "fmt/printf.h"

#include "Instruction.h"

#include "Debugger.h"
#include "Cpu.h"
#include "Executor.h" 
#include "Memory.h"
#include "RomLoader.h"
#include "logger/nestest.h"

int main() {
  initialize_instructions();
  
  // fetch ROM from HD
  
  Cpu cpu;
  DecodeInfo decoded;
  Memory mem = load_ines("resources/nestest.nes");
  
  Executor::power_on(&cpu, &mem);
  cpu.PC = 0xC000;
  //fmt::print("|0x{:>04X}|\n",cpu.PC);

  logger::NesTest log("resources/nestest-out.log");
  Debugger dbg;

  try {
    dbg.set_pc_breakpoint(0xCE42);

    while(true) {
      Executor::fetch_and_decode(cpu, mem, &decoded);
      log.log(cpu, mem, decoded);
      dbg.debug(&cpu, &mem, decoded);

      Executor::execute(&cpu, &mem, decoded);
    }
  }
  catch(std::exception &e) {
    std::cout << "Exception thrown: " << e.what() << std::endl;
  }
  catch(const char*e) {
    std::cout << "Exception thrown: " << e << std::endl;
  }
  
  // ensure flush
  std::cout << std::endl;
  return 0;
}

