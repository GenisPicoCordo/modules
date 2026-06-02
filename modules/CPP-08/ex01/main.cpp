#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "Span.hpp"
#include <numeric>
#include <ctime>
#include <cstdlib>


int main() {
	std::cout << RED << "----Subject test----" << RESET << std::endl;

	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}	

	std::cout << RED << "----Exception test 1----" << RESET << std::endl;

	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << RED << "----Exception test 2----" << RESET << std::endl;

	try {
		Span sp(6);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

    std::cout << RED << "----Random test with large dataset----" << RESET << std::endl;

    try {
        Span sp(10000);

        std::vector<int> randomNumbers(10000);
        srand(time(0));
        for (size_t i = 0; i < randomNumbers.size(); ++i) {
            randomNumbers[i] = rand() % 1000000;
        }

        sp.addNumbersRange(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}