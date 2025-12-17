#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("RandomAnimal") {
    std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
    std::cout << "[AAnimal] Constructor called for AAnimal with type " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
    std::cout << "[AAnimal] Copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    std::cout << "[AAnimal] Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "[AAnimal] Destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return _type;
}