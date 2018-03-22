#include "doctest.h"

#include "Cpu.h"
#include "fmt/format.h"

#include <limits>
#include <cstdint>

TEST_SUITE_BEGIN("CPU Tests");

TEST_CASE("Check packing/unpacking of processor flags") {

  Cpu cpu;

  uint8_t flags = 0;

  // NOTE: bit 5 is always 0, so we explicitly set it as such before testing
  for(auto i = 0; i < std::numeric_limits<uint8_t>::max();++i) {
    cpu.set_flags(i);
    flags = cpu.get_flags();
    auto expected = i & 0xEF;

    auto msg = fmt::format("cpu status flag test failed for value '{}'",i);
    REQUIRE_MESSAGE(flags == expected, msg);
  }
  

  // bit 0
  cpu.set_flags(0);
  flags = cpu.get_flags();
  REQUIRE(flags == 0);
  cpu.C = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 1);
  cpu.C = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 1
  cpu.set_flags(0);
  cpu.Z = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 2);
  cpu.Z = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 2
  cpu.set_flags(0);
  cpu.I = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 4);
  cpu.I = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 3
  cpu.set_flags(0);
  cpu.D = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 8);
  cpu.D = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 4
  cpu.set_flags(0);
  cpu.B = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);
  cpu.B = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 5
  cpu.set_flags(0);
  cpu.U = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 32);
  cpu.U = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 6
  cpu.set_flags(0);
  cpu.V = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 64);
  cpu.V = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);

  //bit 7
  cpu.set_flags(0);
  cpu.N = true;
  flags = cpu.get_flags();
  REQUIRE(flags == 128);
  cpu.N = false;
  flags = cpu.get_flags();
  REQUIRE(flags == 0);
}



TEST_SUITE_END();
