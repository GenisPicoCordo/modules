#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <cctype> 

static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

static bool isValidPhoneNumber(const std::string& str) {
    if (str.length() < 9 || str.length() > 11)
        return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

PhoneBook::PhoneBook() : index(0), total(0) {}

void PhoneBook::addContact(){
    std::string first, last, nick, phone, secret;

    std::cout << "\033[36mFirst name: \033[0m"; std::getline(std::cin, first); first = trim(first);
    std::cout << "\033[36mLast name: \033[0m"; std::getline(std::cin, last); last = trim(last);
    std::cout << "\033[36mNickname: \033[0m"; std::getline(std::cin, nick); nick = trim(nick);
    std::cout << "\033[36mPhone number: \033[0m"; std::getline(std::cin, phone); phone = trim(phone);
    std::cout << "\033[36mDarkest secret: \033[0m"; std::getline(std::cin, secret); secret = trim(secret);

    if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty()) {
        std::cout << "Fields can't be empty." << std::endl;
        return;
    }

    if (!isValidPhoneNumber(phone)) {
        std::cout << "\033[31m[ERROR] Phone number must contain only digits and be 9 to 11 digits long.\033[0m" << std::endl;
        return;
    }

    contacts[index % 8].setContact(first, last, nick, phone, secret);
    index++;
    if (total < 8)
        total++;

    std::cout << "\033[32m✔ Contact saved successfully!\033[0m\n" << std::endl;
}

void PhoneBook::searchContact() const {

    if(total == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout << "\n\033[36m=============== CONTACT LIST ================\n";
    std::cout << "=============================================\n";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < total; i++) {
        contacts[i].displayRow(i);
    }

    std::cout << "=============================================\033[0m\n";

    std::cout << "Enter index to view: ";
    int idx;
    if (!(std::cin >> idx) || idx < 0 || idx >= total) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[31m[ERROR] Invalid index. \033[0m" << std::endl;
    } else {
        std::cin.ignore();
        contacts[idx].displayFull();
    }
}