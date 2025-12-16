#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap name constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap copy assignment operator called " << other._name << std::endl;
    if(this != &other){
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage! (Energy left: " << _energyPoints << ")"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already at 0 hit points and can't take more damage!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot be repaired because it has 0 hit points (it's out)!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot be repaired because it has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points! (HP: " << _hitPoints << ", Energy: " << _energyPoints << ")" << std::endl;
}