/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:34:07 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:34:08 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    if(N <= 0)
        return(NULL);
    Zombie* horde = new Zombie[N];

    for(int i = 0; i < N; i++){
        horde[i].setName(name);
    }
    return horde;
}