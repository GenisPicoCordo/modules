#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
    std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(NULL) {
    std::cout << "[Cat] Copy constructor called" << std::endl;
    if (other._brain)
        _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "[Cat] Copy assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        if (_brain)
            delete _brain;
        if (other._brain)
            _brain = new Brain(*other._brain);
        else
            _brain = NULL;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow..." << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    if (_brain)
        _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (_brain)
        return _brain->getIdea(index);
    return "";
}