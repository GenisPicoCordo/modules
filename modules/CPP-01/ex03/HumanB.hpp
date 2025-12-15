/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:35:58 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:35:59 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
    private:
        std::string _name;
        Weapon*     _weapon;

    public:
        HumanB();
        HumanB(const std::string& name);
        ~HumanB();
        void setWeapon(Weapon& weapon);
        void attack() const;
};

#endif