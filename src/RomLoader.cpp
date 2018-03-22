#include "RomLoader.h"

#include <cstring>
#include <iterator>
#include <limits>
#include <fstream>
#include <vector>

namespace {
  enum class InesVersion {
    None = 0,
    InesArchaic,
    Ines1,
    Ines2
  };

  struct InesHeader {
    uint32_t ines_identifier;
    uint8_t prg_rom_banks;
    uint8_t chr_rom_banks;
    uint8_t flags6;
    uint8_t flags7;
    uint8_t prg_ram_units;
    uint8_t flags9;
    uint8_t flags10;
    uint32_t padding;
  };

  Memory load_archaic_ines(const std::vector<uint8_t> &bin);
  std::vector<uint8_t> load_binaryfile(const std::string &filepath, size_t max_size);
  InesVersion detect_ines_version(InesHeader *h);
};

Memory load_ines(std::string filepath) {
  auto max_size = std::numeric_limits<uint16_t>::max()*2; // give us some leeway
  std::vector<uint8_t> bin = load_binaryfile(filepath, (size_t)max_size);

  if(bin.size() == 0)
    throw "file was empty or nonexistent";

  auto *h = (InesHeader*)&bin[0];

  if(h->ines_identifier != 0x1A53454E)
    throw "ines header not found, this is not a valid ines file";

  auto version = detect_ines_version(h);
  switch(version) {
    case InesVersion::InesArchaic: return load_archaic_ines(bin);
  }
  throw "We currently only support the original version of Ines (aka InesArchaic)";
}

namespace {
  Memory load_archaic_ines(const std::vector<uint8_t> &bin) {
    size_t prg_rombank_size = 16384;
    if(bin.size() < prg_rombank_size + 16)
      throw "file size is too small for archaic ines";

    auto *h = (InesHeader*)&bin[0];

    bool hasTrainer = (h->flags6 & 0x04) > 0;
    if(hasTrainer) throw "We do not currently support roms with trainers.";

    if(h->prg_rom_banks != 1) throw "We currently only support a single rom bank";

    Memory mem;

    // we mirror the PRG rom if there's only 1 prg rom bank, which is all we support at the moment.
    
    std::memcpy(&(mem.raw()[0x8000]), &bin[16], prg_rombank_size);
    std::memcpy(&(mem.raw()[0xC000]), &bin[16], prg_rombank_size);

    return mem;
  }

  // TODO: should really think about a better way to signal that the file was too big
  //
  // NOTE: we check the max size just so we're not slurping in something ridiculous
  //
  std::vector<uint8_t> load_binaryfile(const std::string &filepath, size_t max_size) {
    std::ifstream fin(filepath, std::ios::binary);
    fin.unsetf(std::ios::skipws);

    fin.seekg(0, std::ios::end);
    auto size = (unsigned long)fin.tellg();
    fin.seekg(0, std::ios::beg);

    std::vector<uint8_t> vec;

    if (size >= max_size) return vec;

    vec.reserve(size);

    vec.insert(vec.begin(),
               std::istream_iterator<uint8_t>(fin),
               std::istream_iterator<uint8_t>());
    return vec;
  }

  // this detection isn't exact, but is good enough for getting started.
  // https://wiki.nesdev.com/w/index.php/INES
  InesVersion detect_ines_version(InesHeader *h) {
    if(h->flags7 == 0) return InesVersion::InesArchaic;
    if(h->padding == 0) return InesVersion::Ines1;
    return InesVersion::Ines2;
  }
}
