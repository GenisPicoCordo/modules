#include "DiamondTrap.hpp"

int main() {
    std::cout << "----- DiamondTrap test -----" << std::endl;
    DiamondTrap d("GenisD");

    d.attack("dummy target");
    d.takeDamage(20);
    d.beRepaired(10);
    d.whoAmI();

    std::cout << "\n----- Copy tests -----" << std::endl;
    DiamondTrap d2(d);
    d2.whoAmI();

    DiamondTrap d3;
    d3 = d;
    d3.attack("another dummy");

    std::cout << std::endl;
    return 0;
}
