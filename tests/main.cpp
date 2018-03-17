#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_SUITE_BEGIN("Example Tests");

TEST_CASE("example pass test") {
  REQUIRE(true);
}

TEST_CASE("example fail test") {
  REQUIRE(false);
}

TEST_SUITE_END();
