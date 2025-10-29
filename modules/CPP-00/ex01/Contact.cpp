#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static size_t visibleLength(const std::string& str) {
	size_t count = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if ((str[i] & 0xC0) != 0x80) // ignora bytes de continuación
			++count;
	}
	return count;
}

static std::string formatField(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '\t')
			str[i] = ' ';
	}

	size_t visLen = visibleLength(str);
	if (visLen > 10)
		return str.substr(0, 9) + ".";

	return std::string(10 - visLen, ' ') + str;
}


/*
static std::string formatField(std::string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}
*/
void Contact::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret){
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::displayRow(int index) const {
    std::cout << std::setw(10) << index << "|"
              << formatField(firstName) << "|"
              << formatField(lastName) << "|"
              << formatField(nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}