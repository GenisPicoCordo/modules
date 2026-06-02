#define RED "\033[31m"
#define RESET "\033[0m"

#include <iostream>
#include "swap.hpp"
#include "min.hpp"
#include "max.hpp"

class Awesome {
	private:
		int _n;

	public:
		Awesome(void) : _n(0) {}
		Awesome(int n) : _n(n) {}
		Awesome & operator=(Awesome &a) { _n = a._n; return *this; }

		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

		int get_n() const { return _n; }	
};

std::ostream &operator<<(std::ostream &os, const Awesome &a) { 
	os << a.get_n(); 
	return os; 
}

int main(void)
{
	std::cout << RED << "----Subject test----" << RESET << std::endl;
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << RED << "----Class test----" << RESET << std::endl;
	Awesome e(2), f(4);
	::swap(e, f);
	std::cout << e << " " << f << std::endl;
	std::cout << max(e, f) << std::endl;
	std::cout << min(e, f) << std::endl;
	
	return 0;
}