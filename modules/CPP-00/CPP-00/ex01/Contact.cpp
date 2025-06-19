/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:03:06 by gpico-co          #+#    #+#             */
/*   Updated: 2025/06/19 19:32:33 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setContact(std::string first, std::string last, std::string nick, 
		std::string phone, std::string secret) {
			firstName = first;
	 		lastName = last;
			nickname = nick;
	 		phoneNumber = phone;
			darkestSecret = secret;
		}

void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

static std::string formatField(std::string str) {
	  for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}

void Contact::displayRow(int index) const {
	std::cout << std::setw(10) << index << "|"
			  << formatField(firstName) << "|"
			  << formatField(lastName) << "|"
			  << formatField(nickname) << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty();
}
