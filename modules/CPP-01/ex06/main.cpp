#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) { 
        std::cerr << "Usage: " << argv[0] << " <level>\n"; 
        return 1; 
    }

    Harl h;
    h.complain(argv[1]);
    return 0;
}
