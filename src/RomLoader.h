#ifndef ATOMICNES_ROM_LOADER_H
#define ATOMICNES_ROM_LOADER_H

#include "Memory.h"

#include <string>

Memory load_ines(std::string filepath);

#endif
