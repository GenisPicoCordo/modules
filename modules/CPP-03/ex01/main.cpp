#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "----- ClapTrap test -----" << std::endl;
    ClapTrap c("Genis");
    c.attack("dummy");
    c.takeDamage(5);
    c.beRepaired(3);

    std::cout << "\n----- ScavTrap test -----" << std::endl;
    ScavTrap s("Noemi");
    s.attack("intruder");
    s.takeDamage(20);
    s.beRepaired(10);
    s.guardGate();

    std::cout << "\n----- Copy tests -----" << std::endl;
    ScavTrap s2(s);
    s2.attack("another intruder");

    ScavTrap s3;
    s3 = s;
    s3.guardGate();

    return 0;
}
