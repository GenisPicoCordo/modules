/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:31:32 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 17:21:54 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	
	Zombie myZombie("PACO");
	Zombie myZombie2("PACO2");
	myZombie.announce();
	myZombie2.announce();
	
	Zombie* noemi = newZombie("Noemi");
	noemi->announce();
	delete noemi;
	
	randomChump("Genis");

	return 0;
}