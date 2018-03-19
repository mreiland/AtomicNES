#include "doctest.h"

#include "fmt/format.h"
#include "Instruction.h"

TEST_SUITE_BEGIN("Instruction Tests");

TEST_CASE("Verify Instructions appear correct after initialization") {
  initialize_instructions();

  for(auto i = 0; i <= 0xFF;++i) {
    auto instr = get_instruction(i);
    if(instr->operation == Operation::None) continue;

    std::string info_msg = fmt::format("Checking opcode '{}' -- {}:{}", instr->opcode, to_string(instr->operation), to_string(instr->mode));

    INFO(info_msg);

    std::string msg = fmt::format( "opcode check failed with value '{}'",      instr->opcode);
    REQUIRE_MESSAGE(instr->opcode == i, msg);

    msg = fmt::format("len check failed with value '{}'", instr->len);
    REQUIRE_MESSAGE( (instr->len > 0 && instr->len <= 3), msg);

    msg = fmt::format("cycles check failed with value '{}'", instr->cycles);
    REQUIRE_MESSAGE( (instr->cycles > 0 && instr->cycles <=7), msg);

    msg = fmt::format("page_cycles check failed with value '{}'",  instr->page_cycles);
    REQUIRE_MESSAGE( (instr->page_cycles >= 0 && instr->page_cycles <=2),  msg);
  }
}

TEST_SUITE_END();
