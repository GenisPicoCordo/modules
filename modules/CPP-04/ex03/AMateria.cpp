#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("unknown") {
    std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "[AMateria] Constructor called with type " << _type << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
    std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    std::cout << "[AMateria] Copy assignment operator called" << std::endl;
    (void)other;
    /*if (this != &other)
        _type = other._type;*/
    return *this;
}

AMateria::~AMateria() {
    std::cout << "[AMateria] Destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "[AMateria] does nothing on target" << std::endl; //Comentarlo para q no de mensajes en los test?
}