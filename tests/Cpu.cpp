#include "doctest.h"

#include "Cpu.h"

#include <limits>
#include <cstdint>

TEST_SUITE_BEGIN("CPU Tests");

TEST_CASE("Check packing/unpacking of processor flags") {

  Cpu cpu;

  for(auto i = 0; i < std::numeric_limits<uint8_t>::max();++i) {
    cpu.set_flags(i);
    auto flags = cpu.get_flags();

    REQUIRE(flags == i);
  }
}



TEST_SUITE_END();
