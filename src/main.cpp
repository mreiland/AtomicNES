#include <iostream>
#include <string>

#include "fmt/format.h"
#include "fmt/printf.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Hello, world!" << std::endl;
    
    std::string s = fmt::format("{0}{1}{0}", "abra", "cad");
    std::cout << s << std::endl;
    
    fmt::print("Hello, {}!\n", "world");
    fmt::printf("Hello, {}!", "world");
    
    // appears to be necessary to get fmt::print and fmt::printf to output.
    // std::cout.flush() isn't enough for some odd reason.  We need to either
    // end the above with a \n or do an explicit std::endl;  I'm unsure why
    // std::cout.flush() isn't enough, but there you go...
    // 
    std::cout << std::endl; 
    return 0;
}

