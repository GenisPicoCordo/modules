#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <algorithm> // Para std::lower_bound (búsqueda binaria)
#include <iterator>

class	PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int>  _deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void loadData(int argc, char **argv);
		void sortAndDisplay();
		void sortVector();
		void sortDeque();
};

#endif