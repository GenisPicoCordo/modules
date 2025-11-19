#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("Default") {
    _hitPoints = 100;   // FragTrap
    _energyPoints = 50; // ScavTrap
    _attackDamage = 30; // FragTrap
    std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

// Name constructor
DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _hitPoints = 100;   // FragTrap
    _energyPoints = 50; // ScavTrap
    _attackDamage = 30; // FragTrap
    std::cout << "DiamondTrap name constructor called for " << _name << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

// Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);   // copia la parte ClapTrap (_hitPoints, _energyPoints, etc.)
        _name = other._name;          // copia el nombre propio de DiamondTrap
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

// whoAmI: muestra su nombre y el nombre ClapTrap
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
