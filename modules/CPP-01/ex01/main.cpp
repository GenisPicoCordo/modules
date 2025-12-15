/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:33:35 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:36 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(){
    std::cout << "Let's make an insane horde of noone\n";
    Zombie* horde1 = zombieHorde(0, "Genis");
    for(int i = 0; i < 0; i++){
        horde1[i].announce();
    }
    delete[] horde1;

    std::cout << "Time to make 8\n";
    Zombie* horde2 = zombieHorde(8, "Hugo");
    for(int i = 0; i < 8; i++){
        horde2[i].announce();
    }
    delete[] horde2;

    std::cout << "Attempting to create a horde of size -1\n";
	Zombie* horde3 = zombieHorde(-1, "Noemi");
	for (int i = 0; i < -1; i++){
			horde3[i].announce();
	}
	delete[] horde3;

	std::cout << "Attempting to create a horde of size 10\n";
	Zombie* horde4 = zombieHorde(10, "Eren");
	for (int i = 0; i < 10; i++){
			horde4[i].announce();
	}
	delete[] horde4;

    std::cout << "Trying with parameter\n";
    Zombie paco("PACO");
    paco.announce();
}