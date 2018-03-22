#ifndef ATOMICNES_ROM_NESTEST_LOGGER_H
#define ATOMICNES_ROM_NESTEST_LOGGER_H

#include "Cpu.h"
#include "DecodeInfo.h"
#include "Memory.h"

#include <fstream>
#include <string>


namespace logger {
  class NesTest {
  public:
    NesTest(const std::string &logfile);
    ~NesTest();
    void log(const Cpu &, const Memory &, const DecodeInfo &);
  private:
    std::ofstream *fout_ptr = nullptr;
  };
}
#endif

