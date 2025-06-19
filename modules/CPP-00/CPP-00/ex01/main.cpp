/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:34:06 by gpico-co          #+#    #+#             */
/*   Updated: 2025/06/19 19:30:49 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook pb;
    std::string input;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, input)) {
        std::cout << "\nEOF detected. Exiting." << std::endl;
        break;
    	}
        if (input == "ADD")
            pb.addContact();
        else if (input == "SEARCH")
            pb.searchContact();
        else if (input == "EXIT")
            break;
        else
            std::cout << "Unknown command." << std::endl;
    }
    return 0;
}
