#include "Dog.hpp"

Dog::Dog() : AAnimal("dog"), _brain(new Brain()) {
    std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), _brain(NULL) {
    std::cout << "[Dog] Copy constructor called" << std::endl;
    if (other._brain)
        _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
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

Dog::~Dog() {
    std::cout << "[Dog] Destructor called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
    if (_brain)
        _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    if (_brain)
        return _brain->getIdea(index);
    return "";
}
