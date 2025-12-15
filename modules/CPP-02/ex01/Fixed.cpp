#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
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

Fixed::Fixed(const int num): _value(num << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num): _value(static_cast<int>(roundf(num * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}

float Fixed::toFloat(void) const{
    return static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const{
    return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}