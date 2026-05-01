#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <iostream>
#include "iter.hpp"
#include "printElement.hpp"

class Awesome
{
	private:
		int _n;

	public:
		Awesome( void ) : _n( 42 ) {}
		int get( void ) const { return this->_n; }
};

std::ostream & operator<<( std::ostream & os, Awesome const & rhs ) {
	os << rhs.get();
	return os;
}

template <typename T>

void incrementElement(T &x)
{
	x++;
}

int main(void)
{
	std::cout << RED << "----Subject test----" << RESET << std::endl;

	{
		int arr[] = {1, 2, 3, 4, 5};
		size_t len = sizeof(arr) / sizeof(arr[0]);

		std::cout << GREEN << "Before increment:" << RESET << std::endl;
		iter(arr, len, printElement<int>);

		iter(arr, len, incrementElement<int>);

		std::cout << GREEN << "After increment:" << RESET << std::endl;
		iter(arr, len, printElement<int>);
	}

	{
		char arr[] = {'a', 'b', 'c', 'd'};
		size_t len = sizeof(arr) / sizeof(arr[0]);

		iter(arr, len, printElement<char>);
	}

	{
		std::string arr[] = {"holiwi", "como", "estamos", "maquinaria"};
		size_t len = sizeof(arr) / sizeof(arr[0]);

		iter(arr, len, printElement<std::string>);
	}

	std::cout << RED << "----Class test----" << RESET << std::endl;
	{
		int tab[] = {0, 1, 2, 3, 4};
		Awesome tab2[5];

		iter(tab, 5, printElement<int>);
		iter(tab2, 5, printElement<Awesome>);
	}
}