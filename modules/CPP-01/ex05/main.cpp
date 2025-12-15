/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:39:42 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:39:43 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
  if (argc != 2) { 
        std::cerr << "Usage: " << argv[0] << " <level>\n"; 
        return 1; 
    }

    Harl h;
    h.complain(argv[1]);
    return 0;
}
