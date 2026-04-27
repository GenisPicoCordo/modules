#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
	std::cout << RED << "----Regular test with increment/decrement out of bounds----"
			  << RESET << std::endl;

	try {
		Bureaucrat a;
		Bureaucrat b("Genis", 1);
		Bureaucrat c = b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		a.decrementGrade();
		a.incrementGrade();

		// b is grade 1, increment should throw
		b.incrementGrade();
		b.decrementGrade();

		c.decrementGrade();
		c.decrementGrade();
		c.decrementGrade();
		c.decrementGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "----Grade too low exception test (151)----"
			  << RESET << std::endl;
	try {
		Bureaucrat b("Genis", 151);
		(void)b;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "----Grade too high exception test (0)----"
			  << RESET << std::endl;
	try {
		Bureaucrat b("Genis", 0);
		(void)b;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
