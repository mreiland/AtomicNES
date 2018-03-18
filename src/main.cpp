#include <iostream>
#include <string>

#include "fmt/format.h"
#include "fmt/printf.h"

#include "instructions.h"

#include "Cpu.h"
#include "executor.h"
#include "memory.h"

int main() {
  instructions::initialize();
  
  // fetch ROM from HD
  
  Cpu cpu;
  decode_info decoded;
  memory mem;
  
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

