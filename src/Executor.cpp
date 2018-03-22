#include "Executor.h"

#include "error/unimplemented_error.h"

namespace Executor {
  void reset(Cpu *cpu, Memory *mem) {
    cpu->PC = mem->read16(0xFFFD);
    cpu->SP = 0xFD;
    cpu->set_flags(0x24);
  }
  void power_on(Cpu *cpu, Memory *mem) {
    reset(cpu,mem);
  }
  
  // decode_info will need to carry the instruction around with it, should just use a pointer
  // to the actual instruction to minimize copying
  //
  void fetch_and_decode(const Cpu &cpu, const Memory &mem, DecodeInfo *info) {
    uint16_t opcode = mem.read8(cpu.PC);
    info->instruction = get_instruction(opcode);

    switch(info->instruction->mode) {
      case AddressingMode::Accum: throw error::unimplemented_error("Accumulator addressing mode is not implemented"); break;
      case AddressingMode::IMM:
        info->addr1 = 0;
        info->val1 = mem.read8(cpu.PC+1);
        break;
      case AddressingMode::Impl:
        break;
      case AddressingMode::Rel:   throw error::unimplemented_error("Relative addressing mode is not implemented"); break;
      case AddressingMode::ZP:
        info->addr1 = mem.read8(cpu.PC+1);
        break;
      case AddressingMode::ZPX:   throw error::unimplemented_error("ZeroPage,X addressing mode is not implemented"); break;
      case AddressingMode::ZPY:   throw error::unimplemented_error("ZeroPage,Y addressing mode is not implemented"); break;
      case AddressingMode::ABS:   
        info->addr1 = mem.read16(cpu.PC+1);
        info->val1 = mem.read8(info->addr1);
        break;
      case AddressingMode::ABSX:  throw error::unimplemented_error("Absolute,X addressing mode is not implemented"); break;
      case AddressingMode::ABSY:  throw error::unimplemented_error("Absolute,Y  addressing mode is not implemented"); break;
      case AddressingMode::IND:   throw error::unimplemented_error("Indirect addressing mode is not implemented"); break;
      case AddressingMode::INDX:  throw error::unimplemented_error("Indirect,X addressing mode is not implemented"); break;
      case AddressingMode::INDY:  throw error::unimplemented_error("Indirect,Y addressing mode is not implemented"); break;
    }
  }
  void execute(Cpu *cpu, Memory *mem, const DecodeInfo &decoded) {

    uint16_t pc_increment = decoded.instruction->len;

    switch(decoded.instruction->operation) {
      case Operation::ADC: throw error::unimplemented_error("ADC operation is not implemented"); break; 
      case Operation::AND: throw error::unimplemented_error("AND operation is not implemented"); break; 
      case Operation::ASL: throw error::unimplemented_error("ASL operation is not implemented"); break; 
      case Operation::BCC: throw error::unimplemented_error("BCC operation is not implemented"); break; 
      case Operation::BCS: throw error::unimplemented_error("BCS operation is not implemented"); break; 
      case Operation::BEQ: throw error::unimplemented_error("BEQ operation is not implemented"); break; 
      case Operation::BIT: throw error::unimplemented_error("BIT operation is not implemented"); break; 
      case Operation::BMI: throw error::unimplemented_error("BMI operation is not implemented"); break; 
      case Operation::BNE: throw error::unimplemented_error("BNE operation is not implemented"); break; 
      case Operation::BPL: throw error::unimplemented_error("BPL operation is not implemented"); break; 
      case Operation::BRK: throw error::unimplemented_error("BRK operation is not implemented"); break; 
      case Operation::BVC: throw error::unimplemented_error("BVC operation is not implemented"); break; 
      case Operation::BVS: throw error::unimplemented_error("BVS operation is not implemented"); break; 
      case Operation::CLC: throw error::unimplemented_error("CLC operation is not implemented"); break; 
      case Operation::CLD: throw error::unimplemented_error("CLD operation is not implemented"); break; 
      case Operation::CLI: throw error::unimplemented_error("CLI operation is not implemented"); break; 
      case Operation::CLV: throw error::unimplemented_error("CLV operation is not implemented"); break; 
      case Operation::CMP: throw error::unimplemented_error("CMP operation is not implemented"); break; 
      case Operation::CPX: throw error::unimplemented_error("CPX operation is not implemented"); break; 
      case Operation::CPY: throw error::unimplemented_error("CPY operation is not implemented"); break; 
      case Operation::DEC: throw error::unimplemented_error("DEC operation is not implemented"); break; 
      case Operation::DEX: throw error::unimplemented_error("DEX operation is not implemented"); break; 
      case Operation::DEY: throw error::unimplemented_error("DEY operation is not implemented"); break; 
      case Operation::EOR: throw error::unimplemented_error("EOR operation is not implemented"); break; 
      case Operation::INC: throw error::unimplemented_error("INC operation is not implemented"); break; 
      case Operation::INX: throw error::unimplemented_error("INX operation is not implemented"); break; 
      case Operation::INY: throw error::unimplemented_error("INY operation is not implemented"); break; 
      case Operation::JMP:
        cpu->PC = decoded.addr1;
        pc_increment = 0;
        break;
      case Operation::JSR: throw error::unimplemented_error("JSR operation is not implemented"); break; 
      case Operation::LDA: throw error::unimplemented_error("LDA operation is not implemented"); break; 
      case Operation::LDX:
        cpu->x = decoded.val1;
        cpu->Z = cpu->x == 0;
        cpu->N = cpu->x > 127;
        break;
      case Operation::LDY: throw error::unimplemented_error("LDY operation is not implemented"); break; 
      case Operation::LSR: throw error::unimplemented_error("LSR operation is not implemented"); break; 
      case Operation::NOP: throw error::unimplemented_error("NOP operation is not implemented"); break; 
      case Operation::ORA: throw error::unimplemented_error("ORA operation is not implemented"); break; 
      case Operation::PHA: throw error::unimplemented_error("PHA operation is not implemented"); break; 
      case Operation::PHP: throw error::unimplemented_error("PHP operation is not implemented"); break; 
      case Operation::PLA: throw error::unimplemented_error("PLA operation is not implemented"); break; 
      case Operation::PLP: throw error::unimplemented_error("PLP operation is not implemented"); break; 
      case Operation::ROL: throw error::unimplemented_error("ROL operation is not implemented"); break; 
      case Operation::ROR: throw error::unimplemented_error("ROR operation is not implemented"); break; 
      case Operation::RTI: throw error::unimplemented_error("RTI operation is not implemented"); break; 
      case Operation::RTS: throw error::unimplemented_error("RTS operation is not implemented"); break; 
      case Operation::SBC: throw error::unimplemented_error("SBC operation is not implemented"); break; 
      case Operation::SEC: throw error::unimplemented_error("SEC operation is not implemented"); break; 
      case Operation::SED: throw error::unimplemented_error("SED operation is not implemented"); break; 
      case Operation::SEI: throw error::unimplemented_error("SEI operation is not implemented"); break; 
      case Operation::STA: throw error::unimplemented_error("STA operation is not implemented"); break; 
      case Operation::STX:
        mem->write8(decoded.addr1,cpu->x);
        break;
      case Operation::STY: throw error::unimplemented_error("STY operation is not implemented"); break; 
      case Operation::TAX: throw error::unimplemented_error("TAX operation is not implemented"); break; 
      case Operation::TAY: throw error::unimplemented_error("TAY operation is not implemented"); break; 
      case Operation::TSX: throw error::unimplemented_error("TSX operation is not implemented"); break; 
      case Operation::TXA: throw error::unimplemented_error("TXA operation is not implemented"); break; 
      case Operation::TXS: throw error::unimplemented_error("TXS operation is not implemented"); break; 
      case Operation::TYA: throw error::unimplemented_error("TYA operation is not implemented"); break; 

      case Operation::None: throw "Operation::None was found, this should never happen!";
      default: throw "DEFAULT OPERATION HIT, THIS SHOULD NEVER HAPPEN";
    }

    cpu->PC += pc_increment;
  }
}
