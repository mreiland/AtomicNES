#ifndef ATOMIC_NES_UNIMPLEMENTED_ERROR_H
#define ATOMIC_NES_UNIMPLEMENTED_ERROR_H

#include <stdexcept>

class unimplemented_error : public std::logic_error {
  public:
    unimplemented_error(const std::string &msg) : std::logic_error(msg) { }
    ~unimplemented_error() {}
};


#endif

