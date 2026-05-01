#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include "Array.tpp" 

template <typename T>

class Array {
	private:
		T *_arr;
		unsigned int _size;

	public:
		//Exception class
		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const throw();
		};

		//Constructors and destructor
		Array();
		Array(const unsigned int &n);
		Array(const Array<T> &other);
		~Array();

		//Operator overload
		Array<T> &operator=(const Array<T> &other);
		T& operator[](unsigned int index);

		//Functions
		unsigned int size() const;
};

#endif
