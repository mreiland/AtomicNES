#include "rom_loader.h"

#include <iterator>
#include <fstream>
#include <vector>

Memory load_ines(std::string filepath) {
  std::ifstream fin(filepath, std::ios::binary);
  fin.unsetf(std::ios::skipws);

  fin.seekg(0, std::ios::end);
  auto size = fin.tellg();
  fin.seekg(0, std::ios::beg);

  if(size < 16384 + 16)
    throw "file size is too small for ines";

  uint16_t header;
  fin >> header;

  if((uint8_t)header != 0x4E || uint8_t(header << 8) != 0x45 || uint8_t(header << 8*2) != 0x53 || uint8_t(header << 8*3) != 0x1A)
    throw "ines header not present";

  uint8_t prg_rom_size = header << 8*4;
  uint8_t chr_size = header << 8*5;

  uint8_t flag6 = header << 8*6;
  uint8_t flag7 = header << 8*7;

  uint8_t prg_ram_size = (header << 8*8);

  uint8_t flag9  = header << 8*9;
  uint8_t flag10 = header << 8*10;

  std::vector<uint8_t> vec;
  vec.reserve(size);

  // read the data:
  vec.insert(vec.begin(),
             std::istream_iterator<uint8_t >(fin),
             std::istream_iterator<uint8_t >());

  Memory mem(vec);

  return mem;
}
