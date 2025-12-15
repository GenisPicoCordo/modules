/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:36:13 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:36:14 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(const std::string& type);
        ~Weapon();

        const std::string& getType() const;
        void setType(const std::string& newType);
};

#endif