#include "Executor.h"

#include "error/unimplemented_error.h"

#include <iostream>
#include "fmt/format.h"

// NVUBDIZC
// 10100100 // A4
// 10100101 // A5

//TODO: investigate to see if this wrapping behavior is correct.
//      in this code the SP will continue growing and only wrap
//      on reads and writes. Is that accurate?  Or does the SP
//      value itself also wrap?
namespace  {
  void stack_push8(Cpu *cpu, Memory *mem, uint8_t val) {
    mem->write8(0x100 | uint16_t(cpu->SP),val);
    cpu->SP--;
  }
  uint8_t stack_pop8(Cpu *cpu, Memory *mem) {
    cpu->SP++;
    return mem->read8(0x100 | uint16_t(cpu->SP));
  }
  void stack_push16(Cpu *cpu, Memory *mem, uint16_t val) {
    mem->write16(0x100 | uint16_t(cpu->SP-1),val);
    cpu->SP-=2;
  }
  uint16_t stack_pop16(Cpu *cpu, Memory *mem) {
    cpu->SP+=2;
    return mem->read16(0x100 | uint16_t(cpu->SP-1));
  }
}

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
      case AddressingMode::Rel:
        info->val1 = mem.read8(cpu.PC+1);
        info->addr1 = cpu.PC+(int8_t)info->val1;
        break;
      case AddressingMode::ZP:
        info->addr1 = mem.read8(cpu.PC+1);
        info->val1 = mem.read8(info->addr1);
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
      case Operation::ADC: {
        uint16_t a = cpu->a;
        uint16_t b = decoded.val1;
        uint16_t c = cpu->C;

        uint16_t result = a + b + c;
        cpu->a = result&0xFF;

        cpu->set_Z(cpu->a);
        cpu->set_N(cpu->a);

        cpu->C = result > 0xFF;
        cpu->V = ((a^b)&0x80) == 0 && ((a^cpu->a)&0x80) != 0;

        break;
      }
      case Operation::AND:
        cpu->a = cpu->a & decoded.val1;
        cpu->set_Z(cpu->a);
        cpu->set_N(cpu->a);
        break;
      case Operation::ASL: throw error::unimplemented_error("ASL operation is not implemented"); break; 
      case Operation::BCC:
        if(!cpu->C) cpu->PC = decoded.addr1;
        break;
      case Operation::BCS:
        if(cpu->C) cpu->PC = decoded.addr1;
        break;
      case Operation::BEQ:
        if(cpu->Z) cpu->PC = decoded.addr1;
        break;
      case Operation::BIT:
        cpu->V = (decoded.val1 >> 6) & 1;
        cpu->set_Z(decoded.val1 & cpu->a);
        cpu->set_N(decoded.val1);
        break;
      case Operation::BMI:
        if(cpu->N) cpu->PC = decoded.addr1;
        break;
      case Operation::BNE:
        if(!cpu->Z) cpu->PC = decoded.addr1;
        break;
      case Operation::BPL:
        if(!cpu->N) cpu->PC = decoded.addr1;
        break;
      case Operation::BRK: throw error::unimplemented_error("BRK operation is not implemented"); break; 
      case Operation::BVC:
        if(!cpu->V) cpu->PC = decoded.addr1;
        break;
      case Operation::BVS:
        if(cpu->V) cpu->PC = decoded.addr1;
        break;
      case Operation::CLC:
        cpu->C = false;
        break;
      case Operation::CLD:
        cpu->D = false;
        break;
      case Operation::CLI: throw error::unimplemented_error("CLI operation is not implemented"); break; 
      case Operation::CLV:
        cpu->V = false;
        break;
      case Operation::CMP:
        cpu->compare(cpu->a, decoded.val1);
        break;
      case Operation::CPX:
        cpu->compare(cpu->x, decoded.val1);
        break;
      case Operation::CPY:
        cpu->compare(cpu->y, decoded.val1);
        break;
      case Operation::DEC: throw error::unimplemented_error("DEC operation is not implemented"); break; 
      case Operation::DEX:
        cpu->x--;
        cpu->set_N(cpu->x);
        cpu->set_Z(cpu->x);
        break;
      case Operation::DEY:
        cpu->y--;
        cpu->set_N(cpu->y);
        cpu->set_Z(cpu->y);
        break;
      case Operation::EOR:
        cpu->a = cpu->a ^ decoded.val1;
        cpu->set_N(cpu->a);
        cpu->set_Z(cpu->a);
        break;
      case Operation::INC: throw error::unimplemented_error("INC operation is not implemented"); break; 
      case Operation::INX:
        cpu->x++;
        cpu->set_N(cpu->x);
        cpu->set_Z(cpu->x);
        break;
      case Operation::INY:
        cpu->y++;
        cpu->set_N(cpu->y);
        cpu->set_Z(cpu->y);
        break;
      case Operation::JMP:
        cpu->PC = decoded.addr1;
        pc_increment = 0;
        break;
      case Operation::JSR:
        // pushes 1 before the next instruction so when we pop the PC will increment and will be 
        // pointed at the next opcode
        //
        stack_push16(cpu, mem, cpu->PC + decoded.instruction->len-1);
        cpu->PC = decoded.addr1;
        pc_increment = 0;
        break;
      case Operation::LDA:
        cpu->a = decoded.val1;
        cpu->set_Z(cpu->a);
        cpu->set_N(cpu->a);
        break;
      case Operation::LDX:
        cpu->x = decoded.val1;
        cpu->set_Z(cpu->x);
        cpu->set_N(cpu->x);
        break;
      case Operation::LDY:
        cpu->y = decoded.val1;
        cpu->set_Z(cpu->y);
        cpu->set_N(cpu->y);
        break;
      case Operation::LSR: throw error::unimplemented_error("LSR operation is not implemented"); break; 
      case Operation::NOP:
        break;
      case Operation::ORA: {
        cpu->a = cpu->a | decoded.val1;
        cpu->set_Z(cpu->a);
        cpu->set_N(cpu->a);
        break;
      }
      case Operation::PHA:
        stack_push8(cpu,mem,cpu->a);
        break;
      case Operation::PHP: {
        auto result = cpu->get_flags();
        stack_push8(cpu,mem,result | 0x30);
        break;
      }
      case Operation::PLA:
        cpu->a = stack_pop8(cpu,mem);
        cpu->set_Z(cpu->a);
        cpu->set_N(cpu->a);
        break;
      case Operation::PLP:
        cpu->set_flags((stack_pop8(cpu, mem)&0xEF) | 0x20);
        break;
      case Operation::ROL: throw error::unimplemented_error("ROL operation is not implemented"); break; 
      case Operation::ROR: throw error::unimplemented_error("ROR operation is not implemented"); break; 
      case Operation::RTI: throw error::unimplemented_error("RTI operation is not implemented"); break; 
      case Operation::RTS:
        cpu->PC = stack_pop16(cpu, mem) + 1;
        pc_increment = 0;
        break;
      case Operation::SBC: {
        uint8_t a = cpu->a;
        uint8_t b = decoded.val1;
        uint8_t c = cpu->C;
        int16_t result = a-b-(1-c);

        cpu->a = result;
        cpu->set_Z(cpu->a);
        cpu->set_N(cpu->a);

        cpu->C = result >= 0;
        cpu->V = ((a^b)&0x80) != 0 && ((a^cpu->a)&0x80) != 0;

        break;
      }
      case Operation::SEC:
        cpu->C = true;
        break;
      case Operation::SED:
        cpu->D = true;
        break;
      case Operation::SEI:
        cpu->I = true;
        break;
      case Operation::STA:
        mem->write8(decoded.addr1,cpu->a);
        break;
      case Operation::STX:
        mem->write8(decoded.addr1,cpu->x);
        break;
      case Operation::STY: throw error::unimplemented_error("STY operation is not implemented"); break; 
      case Operation::TAX:
        cpu->x = cpu->a;
        cpu->set_N(cpu->x);
        cpu->set_Z(cpu->x);
        break;
      case Operation::TAY:
        cpu->y = cpu->a;
        cpu->set_N(cpu->y);
        cpu->set_Z(cpu->y);
        break;
      case Operation::TSX:
        cpu->x = cpu->SP;
        cpu->set_N(cpu->x);
        cpu->set_Z(cpu->x);
        break;
      case Operation::TXA:
        cpu->a = cpu->x;
        cpu->set_N(cpu->a);
        cpu->set_Z(cpu->a);
        break;
      case Operation::TXS:
        cpu->SP = cpu->x;
        break;
      case Operation::TYA:
        cpu->a = cpu->y;
        cpu->set_N(cpu->a);
        cpu->set_Z(cpu->a);
        break;
      case Operation::None: throw "Operation::None was found, this should never happen!";
      default: throw "DEFAULT OPERATION HIT, THIS SHOULD NEVER HAPPEN";
    }

    cpu->PC += pc_increment;
  }
}
