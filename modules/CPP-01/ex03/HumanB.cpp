/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:35:53 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:35:54 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
