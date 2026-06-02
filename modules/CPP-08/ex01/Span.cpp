#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(const unsigned int &n) : _size(n) {}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_size = other._size;
		this->_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(const int &number) {
	if (this->_numbers.size() >= this->_size)
		throw(Span::OversizeException());
	this->_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (this->_numbers.size() < 2)
		throw(Span::NoNumbersException());

	std::vector<int> copy = this->_numbers;
	std::sort(copy.begin(), copy.end());

	int shortest = INT_MAX;

	for (size_t i = 1; i < copy.size(); i++) {
		long currentSpan = static_cast<long>(copy[i]) - static_cast<long>(copy[i - 1]);
		if (currentSpan < shortest)
			shortest = currentSpan;
	}
	return (shortest);
}

int Span::longestSpan() const {
	if (this->_numbers.size() < 2)
		throw(Span::NoNumbersException());

	std::vector<int>::const_iterator min = std::min_element(this->_numbers.begin(), this->_numbers.end());
	std::vector<int>::const_iterator max = std::max_element(this->_numbers.begin(), this->_numbers.end());

	return (*max - *min);
}

const char *Span::OversizeException::what() const throw() {
	return ("Can't add more numbers because container is full!");
}

const char *Span::NoNumbersException::what() const throw() {
	return ("Can't calculate span because container doesn't have enough numbers!");
}