/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:33:44 by gpico-co          #+#    #+#             */
/*   Updated: 2025/06/19 19:41:56 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

PhoneBook::PhoneBook() : index(0), total(0) {}

static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

static bool isValidPhoneNumber(const std::string& str) {
    if (str.length() < 6 || str.length() > 15)
        return false;

    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::addContact() {
    std::string first, last, nick, phone, secret;

    std::cout << "First name: "; std::getline(std::cin, first);
	first = trim(first);
    std::cout << "Last name: "; std::getline(std::cin, last);
	last = trim(last);
    std::cout << "Nickname: "; std::getline(std::cin, nick);
	nick = trim(nick);
    std::cout << "Phone number: "; std::getline(std::cin, phone);
	phone = trim(phone);
	
	 if (!isValidPhoneNumber(phone)) {
        std::cout << "Phone number must contain only digits and be 6 to 15 digits long." << std::endl;
        return;
    }
	
    std::cout << "Darkest secret: "; std::getline(std::cin, secret);
	secret = trim(secret);

    if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty()) {
        std::cout << "Fields can't be empty." << std::endl;
        return;
    }

    contacts[index % 8].setContact(first, last, nick, phone, secret);
    index++;
    if (total < 8) total++;
}

void PhoneBook::searchContact() const {
    if (total == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < total; ++i)
        contacts[i].displayRow(i);

    std::cout << "Enter index to view: ";
    int idx;
    if (!(std::cin >> idx) || idx < 0 || idx >= total) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
    } else {
        std::cin.ignore();
        contacts[idx].displayFull();
    }
}


