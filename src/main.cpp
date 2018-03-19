#include <iostream>
#include <string>

#include "fmt/format.h"
#include "fmt/printf.h"

#include "Instruction.h"

#include "Cpu.h"
#include "executor.h"
#include "Memory.h"
#include "rom_loader.h"

int main() {
  initialize_instructions();
  
  // fetch ROM from HD
  
  Cpu cpu;
  DecodeInfo decoded;
  Memory mem = load_ines("");
  
  executor::power_on(&cpu, &mem);
  
  while(true) {
    decoded = executor::fetch_and_decode(&cpu, &mem);
    //log_info(decode_info);
    executor::execute(&cpu, &mem, decoded);
  }
  
  // ensure flush
  std::cout << std::endl;
  return 0;
}

