#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(700);
	vec.push_back(800);
	vec.push_back(900);

	std::cout << RED << "----easyfind test----" << RESET << std::endl;

	try {
		std::vector<int>::iterator b = easyfind(vec, 1);
		std::cout << "Found with easyfind: " << *b << std::endl;
		
		b = easyfind(vec, 50);
		std::cout << "Found with easyfind: " << *b << std::endl;

		b = easyfind(vec, 900);
		std::cout << "Found with easyfind: " << *b << std::endl;

		b = easyfind(vec, 4);
		std::cout << "Found with easyfind: " << *b << std::endl;
		
	} catch (const std::runtime_error &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << RED << "----std::find test----" << RESET << std::endl;

	try {
		std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 1);
		if (it != vec.end())
			std::cout << "Found with std::find: " << *it << std::endl;
		else
			std::cout << "Value not found with std::find" << std::endl;

		it = std::find(vec.begin(), vec.end(), 50);
		if (it != vec.end())
			std::cout << "Found with std::find: " << *it << std::endl;
		else
			std::cout << "Value not found with std::find" << std::endl;

		it = std::find(vec.begin(), vec.end(), 900);
		if (it != vec.end())
			std::cout << "Found with std::find: " << *it << std::endl;
		else
			std::cout << "Value not found with std::find" << std::endl;
			
		it = std::find(vec.begin(), vec.end(), 4);
		if (it != vec.end())
			std::cout << "Found with std::find: " << *it << std::endl;
		else
			std::cout << "Value not found with std::find" << std::endl;
	} catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
}