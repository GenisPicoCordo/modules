#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Genís");
    ClapTrap b("Noemi");
    std::cout << std::endl;

    a.attack("Noemi");
    b.takeDamage(0);
    std::cout << std::endl;

    b.attack("Genís");
    a.takeDamage(5);
    a.beRepaired(3);
    std::cout << std::endl;

    for(int i = 0; i < 12; i++) {
        a.attack("Dummy target");
    }
    std::cout << std::endl;

    ClapTrap c(a);
    c.attack("someone");
    std::cout << std::endl;

    c = b;
    c.attack("another random");
    std::cout << std::endl;

    return 0;

}