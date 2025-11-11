#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
    std::cout << "[DEBUG]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info() {
    std::cout << "[INFO]\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
    std::cout << "[WARNING]\n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error() {
    std::cout << "[ERROR]\n" << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(const std::string& level) {
  static const char* names[4] = {"DEBUG","INFO","WARNING","ERROR"};
  int idx = -1;
  
  for (int i = 0; i < 4; ++i){
    if (level == names[i]) { 
        idx = i; 
        break; 
    }
  }

  switch (idx) {
    case 0:
      debug();
      break;
    case 1:
      info();
      break;
    case 2: 
      warning();
      break;
    case 3: 
      error(); 
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]\n";
  }
}
