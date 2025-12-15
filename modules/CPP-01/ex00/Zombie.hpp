/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:33:22 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:37:14 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce() const;
};

/*HEAP*/
Zombie* newZombie(std::string name);
/*STACK*/
void randomChump(std::string name);

#endif