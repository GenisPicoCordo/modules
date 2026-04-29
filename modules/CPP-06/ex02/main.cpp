#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int randomValue = std::rand() % 3;

	if (randomValue == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A);
	}
	else if (randomValue == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return (new C);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	std::cout << "Unknown" << std::endl;
}

int main(void)
{
	std::srand(std::time(NULL));

	Base *obj = generate();

	std::cout << "Identify by pointer: ";
	identify(obj);

	std::cout << "Identify by reference: ";
	identify(*obj);

	delete obj;

	return (0);
}