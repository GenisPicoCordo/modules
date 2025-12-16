#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "----- FragTrap test -----" << std::endl;
    FragTrap f("GenisFrag");

    f.attack("dummy target");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << "\n----- Copy tests -----" << std::endl;
    FragTrap f2(f);
    f2.highFivesGuys();

    FragTrap f3;
    f3 = f;
    f3.attack("another dummy");

    std::cout << std::endl;
    return 0;
}
