#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "Form.hpp"

int main() {
	std::cout << RED << "Regular test" << RESET << std::endl;

	try {
	Bureaucrat a("Genis", 1);
	Bureaucrat b("Noemi", 149);
	Bureaucrat c("Eren", 100);

	Form f1("Form1", 150, 140);
	Form f2("Form2", 1, 1);
	Form f3("Form3", 100, 90);

	f1.beSigned(b);
	f1.beSigned(a);

	f2.beSigned(b);
	f2.beSigned(c);
	f2.beSigned(a);

	f3.beSigned(b);
	f3.beSigned(c);
	}
	catch(const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "Testing Form creaton with out of bounds grades" << RESET << std::endl;

	try {
		Bureaucrat d("Genis", 1);

		Form f1("Form4", 151, 100);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat e("Genis", 1);

		Form f1("Form5", 150, 0);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}