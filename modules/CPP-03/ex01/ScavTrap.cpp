#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(): ClapTrap("DefaultScav") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called for " << _name << std::endl;
}

// Constructor con nombre
ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap name constructor called for " << _name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

// Operador de asignación
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other); // reutilizamos el de ClapTrap
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

// Sobrescribe attack()
void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage! (Energy left: " << _energyPoints << ")"
              << std::endl;
}

// Nueva función
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
