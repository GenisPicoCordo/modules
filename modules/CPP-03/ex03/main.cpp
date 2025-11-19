#include "DiamondTrap.hpp"

int main() {
    std::cout << "----- DiamondTrap test -----" << std::endl;
    DiamondTrap d("GenisD");

    d.attack("dummy target");   // viene de ScavTrap
    d.takeDamage(20);           // heredado de ClapTrap
    d.beRepaired(10);           // heredado de ClapTrap
    d.whoAmI();                 // propio de DiamondTrap

    std::cout << "\n----- Copy tests -----" << std::endl;
    DiamondTrap d2(d);
    d2.whoAmI();

    DiamondTrap d3;
    d3 = d;
    d3.attack("another dummy");

    std::cout << std::endl;
    return 0;
}
