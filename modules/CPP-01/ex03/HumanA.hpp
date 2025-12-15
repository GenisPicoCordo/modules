/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:35:50 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 17:08:36 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
    private:
        std::string _name;
        Weapon& _weapon;
    public:
        HumanA();
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        void attack() const;
};

#endif