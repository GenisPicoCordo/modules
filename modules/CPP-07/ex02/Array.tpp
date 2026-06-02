#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

//Constructors and destructor
template <typename T>

Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>

Array<T>::Array(const unsigned int &n): _size(n) {
	this->_arr = new T[n]();
}

template <typename T>

Array<T>::Array(const Array<T> &other): _size(other.size()) {
	this->_arr = new T[this->_size]();
	for (unsigned int i = 0; i < this->_size; i++){
		this->_arr[i] = other._arr[i];
	}
}

template <typename T>

Array<T>::~Array() {
	delete[] this->_arr;
}

//Operator overloads
template <typename T>

Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other){
		this->_size = other.size();	
		delete[] this->_arr;
		this->_arr = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++){
			this->_arr[i] = other._arr[i];
		}
	}
	return (*this);
}

template <typename T>

T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw (Array::OutOfBoundsException());
	return (_arr[index]);
}

//Functions
template <typename T>

unsigned int Array<T>::size() const {
	return (this->_size);
}

//Exception messages
template <typename T>

const char *Array<T>::OutOfBoundsException::what() const throw() {
	return ("Index is out of bounds!!");
}

#endif
