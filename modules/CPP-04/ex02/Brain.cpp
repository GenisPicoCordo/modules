#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] Default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        _ideas[i] = "";
    }
}

Brain::Brain(const Brain &other) {
    std::cout << "[Brain] Copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "[Brain] Copy assigment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor called" << std::endl;
}

const std::string &Brain::getIdea(int index) const {
    static std::string empty = "";
    if (index < 0 || index >= 100)
        return empty;
    return _ideas[index];
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index < 0 || index >= 100)
        return;
    _ideas[index] = idea;
}