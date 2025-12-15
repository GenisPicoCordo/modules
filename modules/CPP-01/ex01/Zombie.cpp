/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:33:57 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:58 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){
    std::cout << "Zombie constructor with parameter called!\n";
    _name = name;
}

Zombie::Zombie(){
    std::cout << "Zombie default constructor called!\n";
    _name = "";
}

Zombie::~Zombie() {
	std::cout << "Destroying zombie: " << _name << std::endl;
}

void Zombie::announce() const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
    _name = name;
}