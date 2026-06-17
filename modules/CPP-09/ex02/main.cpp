#include "PmergeMe.hpp"

bool	isPositiveInteger(const std::string &s) 
{
	if (s.empty())
		return false;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	// Validar si el número desborda un int (INT_MAX)
	long val = std::atol(s.c_str());
	return (val >= 0 && val <= 2147483647);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Usage ./PmergeMe [positive integers...]" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++) 
	{
		if (!isPositiveInteger(argv[i])) 
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}

	try {
		PmergeMe solver;
		solver.loadData(argc, argv);
		solver.sortAndDisplay();
	} catch (const std::exception &e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}