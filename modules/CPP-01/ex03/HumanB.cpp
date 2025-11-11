#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
: _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

HumanB::~HumanB(){
	std::cout << "HumanB " << this->_name << " destroyed!\n";
}

void HumanB::attack() const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " tries to attack but has no weapon" << std::endl;
}
