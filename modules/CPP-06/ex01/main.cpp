#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data original;

	original.n = 42;
	original.str = "eybrodah";

	uintptr_t raw = Serializer::serialize(&original);
	Data *result = Serializer::deserialize(raw);

	std::cout << "Original pointer:     " << &original << std::endl;
	std::cout << "Deserialized pointer: " << result << std::endl;

	if (result == &original)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are different" << std::endl;

	std::cout << "Data n: " << result->n << std::endl;
	std::cout << "Data str: " << result->str << std::endl;

	return (0);
}