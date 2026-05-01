#ifndef PRINTELEMENT_HPP
# define PRINTELEMENT_HPP

# include <iostream>

template <typename T>

void printElement(T const &t)
{
	std::cout << t << std::endl;
}

#endif