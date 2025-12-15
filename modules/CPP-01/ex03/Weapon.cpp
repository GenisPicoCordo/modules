/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:10 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 17:08:28 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) {
    std::cout << "New weapon created!\n";
    _type = type;
}

Weapon::~Weapon() {
    std::cout << "Weapon destroyed!\n";
}
        
const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string& newType) {
    _type = newType;
}