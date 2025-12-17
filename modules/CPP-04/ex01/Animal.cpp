#include "Animal.hpp"

Animal::Animal(): _type("RandomAnimal") {
    std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type): _type(type) {
    std::cout << "[Animal] Constructor called for Animal with type " << _type << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "[Animal] Copy assignment operator called" << std::endl;
    if(this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Default destructor called" << std::endl;
}

std::string Animal::getType() const {
    return (this->_type);
}

void Animal::makeSound() const {
    std::cout << "[Animal] * generic animal sound *" << std::endl;
}