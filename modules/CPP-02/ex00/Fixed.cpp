#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called\n";
	*this = other;	
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other){
		this->_value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Fixed destructor called\n";
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called called\n";
	this->_value = raw;
}