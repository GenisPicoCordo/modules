/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:09:25 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 12:09:26 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void DisplayTitle() {
	std::cout << "\033[36m"; // Color cyan
	std::cout << "=============================================" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "||             WELCOME TO THE              ||" << std::endl;
	std::cout << "||                PHONEBOOK                ||" << std::endl;
	std::cout << "||                                         ||" << std::endl;
	std::cout << "=============================================\033[0m\n" << std::endl << std::endl;
}

int main() {

    DisplayTitle();
    PhoneBook myPhonebook;
    std::string answer;

    while (42)
    {
        std::cout << "\033[36mInstructions:\033[0m\n";
        std::cout << "  > Type '\033[33mADD\033[0m'    to register a new contact.\n";
        std::cout << "  > Type '\033[33mSEARCH\033[0m' to look up existing contacts.\n";
        std::cout << "  > Type '\033[33mEXIT\033[0m'   to close the application.\n";

        std::getline(std::cin, answer);
        
        if (std::cin.eof()) {
            std::cout << "\nEOF detected. Exiting." << std::endl;
            break;
        }
        if (answer == "ADD") {
            myPhonebook.addContact();
        } else if (answer == "SEARCH") {
            myPhonebook.searchContact();
        } else if (answer == "EXIT") {
            break;
        } else {
            std::cout << "Command not allowed, please select one of the following options: " << std::endl;
        }
    }
    return 0;
}