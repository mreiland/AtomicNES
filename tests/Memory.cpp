#include "doctest.h"

#include "Memory.h"

TEST_SUITE_BEGIN("Memory Tests");

TEST_CASE("read/write 8 bit values") {
  Memory mem;

  // test the boundaries at the beginning of memory
  mem.write8(0x00,0xF);
  REQUIRE(mem.read8(0x00) == 0xF);

  mem.write8(0x01,0xA);
  REQUIRE(mem.read8(0x00) == 0xF);
  REQUIRE(mem.read8(0x01) == 0xA);

  mem.write8(0x00,0xC);
  REQUIRE(mem.read8(0x00) == 0xC);
  REQUIRE(mem.read8(0x01) == 0xA);

  // test the boundaries at the end of memory
  mem.write8(0xFFFF,0xF);
  REQUIRE(mem.read8(0xFFFF) == 0xF);

  mem.write8(0xFFFD,0xA);
  REQUIRE(mem.read8(0xFFFF) == 0xF);
  REQUIRE(mem.read8(0xFFFD) == 0xA);

  mem.write8(0xFFFF,0xC);
  REQUIRE(mem.read8(0xFFFF) == 0xC);
  REQUIRE(mem.read8(0xFFFD) == 0xA);
}

TEST_CASE("read/write 16 bit values") {
  Memory mem;

  // test the boundaries at the beginning of memory
  mem.write16(0x00, 0xFFFF);
  REQUIRE(mem.read16(0x00) == 0xFFFF);

  mem.write16(0x02, 0xFFFA);
  REQUIRE(mem.read16(0x00) == 0xFFFF);
  REQUIRE(mem.read16(0x02) == 0xFFFA);

  // test the boundaries at the end of memory
  mem.write16(0xFFFD, 0xFFFF);
  REQUIRE(mem.read16(0xFFFD) == 0xFFFF);

  mem.write16(0xFFFB, 0xFFFA);
  REQUIRE(mem.read16(0xFFFD) == 0xFFFF);
  REQUIRE(mem.read16(0xFFFB) == 0xFFFA);

  // we test writing a 16 bit value to the very last byte in memory.  We expect this
  // to wrap and write to the very first byte in memory so in preparation we write 0
  // to the first byte to ensure we can tell if the wrapped write does not write properly.
  //
  mem.write8(0x00,0);
  mem.write16(0xFFFF, 0xFFFF);
  REQUIRE(mem.read16(0xFFFF) == 0xFFFF);

  REQUIRE(mem.read8(0x00) == 0xFF);
  REQUIRE(mem.read8(0xFFFF) == 0xFF);
}

TEST_SUITE_END();
