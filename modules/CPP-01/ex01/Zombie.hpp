/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:34:02 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:34:03 by gpico-co         ###   ########.fr       */
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
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif