#include <iostream>
#include <string>

#include "fmt/format.h"
#include "fmt/printf.h"

#include "Instruction.h"

#include "Cpu.h"
#include "Executor.h"
#include "Memory.h"
#include "RomLoader.h"

int main() {
  initialize_instructions();
  
  // fetch ROM from HD
  
  Cpu cpu;
  DecodeInfo decoded;
  Memory mem = load_ines("../resources/nestest.nes");
  
  Executor::power_on(&cpu, &mem);
  
  while(true) {
    decoded = Executor::fetch_and_decode(&cpu, &mem);
    //log_info(decode_info);
    Executor::execute(&cpu, &mem, decoded);
  }
  
  // ensure flush
  std::cout << std::endl;
  return 0;
}

