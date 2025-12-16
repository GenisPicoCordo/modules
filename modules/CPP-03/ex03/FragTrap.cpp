#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("DefaultFrag") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap name constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " launches a powerful attack on " << target
              << ", causing " << _attackDamage
              << " points of damage! (Energy left: " << _energyPoints << ")"
              << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " is asking for a positive high five! ✋" << std::endl;
}