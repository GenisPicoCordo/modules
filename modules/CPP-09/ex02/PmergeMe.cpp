#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::loadData(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int val = std::atoi(argv[i]);
		_vector.push_back(val);
		_deque.push_back(val);
	}
}

// Genera la secuencia de índices de Jacobsthal hasta n
std::vector<size_t> generateJacobsthal(size_t n)
{
	std::vector<size_t> j;
	if (n == 0) return j;
	j.push_back(1);
	if (n == 1) return j;
	j.push_back(3);
	while (true)
	{
		size_t next = j.back() + 2 * j[j.size() - 2];
		if (next >= n) break;
		j.push_back(next);
	}
	return j;
}

// --- LÓGICA PARA VECTOR ---
void PmergeMe::sortVector()
{
	if (_vector.size() <= 1) return;

	// 1. Gestión del elemento impar (straggler)
	int straggler = -1;
	bool hasStraggler = false;
	if (_vector.size() % 2 != 0)
	{
		straggler = _vector.back();
		_vector.pop_back();
		hasStraggler = true;
	}

	// 2. Crear parejas y ordenar cada pareja (Grande, Pequeño)
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		if (_vector[i] < _vector[i + 1])
			pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
		else
			pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
	}

	// 3. Ordenar recursivamente los grandes extrayéndolos en un vector temporal
	std::vector<int> larges;
	for (size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].first);

	// Recursión: ordenar los grandes con el mismo algoritmo
	// Para que la recursión funcione, usamos _vector temporalmente
	std::vector<int> saved = _vector;
	_vector = larges;
	sortVector();
	larges = _vector;
	_vector = saved;

	// Reordenar pairs según el nuevo orden de larges
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < larges.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == larges[i])
			{
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	pairs = sortedPairs;

	// 4. Construir Main Chain con los grandes e insertar pend[0] al inicio
	std::vector<int> mainChain;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	// pend[0] es siempre <= pairs[0].first, se inserta al inicio
	mainChain.insert(mainChain.begin(), pend[0]);

	// 5. Inserción del resto de pend usando Jacobsthal + búsqueda binaria acotada
	std::vector<size_t> jacobIdx = generateJacobsthal(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t i = 0; i < jacobIdx.size(); ++i)
	{
		size_t idx = jacobIdx[i];
		if (idx >= pend.size()) idx = pend.size() - 1;

		// Insertar desde idx bajando hasta el primer no insertado
		while (idx > 0 && !inserted[idx])
		{
			// Acotar la búsqueda: pend[idx] < pairs[idx].first
			// pairs[idx].first está en mainChain; buscamos su posición como límite
			std::vector<int>::iterator bound =
				std::lower_bound(mainChain.begin(), mainChain.end(), pairs[idx].first);
			std::vector<int>::iterator it =
				std::lower_bound(mainChain.begin(), bound, pend[idx]);
			mainChain.insert(it, pend[idx]);
			inserted[idx] = true;
			idx--;
		}
	}

	// Insertar cualquier elemento de pend que haya quedado sin insertar
	for (size_t i = 1; i < pend.size(); ++i)
	{
		if (!inserted[i])
		{
			std::vector<int>::iterator bound =
				std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
			std::vector<int>::iterator it =
				std::lower_bound(mainChain.begin(), bound, pend[i]);
			mainChain.insert(it, pend[i]);
			inserted[i] = true;
		}
	}

	// Insertar el straggler si existía
	if (hasStraggler)
	{
		std::vector<int>::iterator it =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	_vector = mainChain;
}

// --- LÓGICA PARA DEQUE ---
void PmergeMe::sortDeque()
{
	if (_deque.size() <= 1) return;

	int straggler = -1;
	bool hasStraggler = false;
	if (_deque.size() % 2 != 0)
	{
		straggler = _deque.back();
		_deque.pop_back();
		hasStraggler = true;
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < _deque.size(); i += 2)
	{
		if (_deque[i] < _deque[i + 1])
			pairs.push_back(std::make_pair(_deque[i + 1], _deque[i]));
		else
			pairs.push_back(std::make_pair(_deque[i], _deque[i + 1]));
	}

	// Recursión sobre los grandes
	std::deque<int> larges;
	for (size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].first);

	std::deque<int> saved = _deque;
	_deque = larges;
	sortDeque();
	larges = _deque;
	_deque = saved;

	// Reordenar pairs según nuevo orden de larges
	std::deque<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < larges.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == larges[i])
			{
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	pairs = sortedPairs;

	std::deque<int> mainChain;
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	mainChain.push_front(pend[0]);

	std::vector<size_t> jacobIdx = generateJacobsthal(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t i = 0; i < jacobIdx.size(); ++i)
	{
		size_t idx = jacobIdx[i];
		if (idx >= pend.size()) idx = pend.size() - 1;

		while (idx > 0 && !inserted[idx])
		{
			std::deque<int>::iterator bound =
				std::lower_bound(mainChain.begin(), mainChain.end(), pairs[idx].first);
			std::deque<int>::iterator it =
				std::lower_bound(mainChain.begin(), bound, pend[idx]);
			mainChain.insert(it, pend[idx]);
			inserted[idx] = true;
			idx--;
		}
	}

	// Insertar cualquier elemento de pend que haya quedado sin insertar
	for (size_t i = 1; i < pend.size(); ++i)
	{
		if (!inserted[i])
		{
			std::deque<int>::iterator bound =
				std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
			std::deque<int>::iterator it =
				std::lower_bound(mainChain.begin(), bound, pend[i]);
			mainChain.insert(it, pend[i]);
			inserted[i] = true;
		}
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator it =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	_deque = mainChain;
}

void PmergeMe::sortAndDisplay()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	// Medir Vector
	struct timespec startVec, endVec;
	clock_gettime(CLOCK_MONOTONIC, &startVec);
	sortVector();
	clock_gettime(CLOCK_MONOTONIC, &endVec);
	double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1000000.0
	               + (endVec.tv_nsec - startVec.tv_nsec) / 1000.0;

	// Medir Deque
	struct timespec startDeq, endDeq;
	clock_gettime(CLOCK_MONOTONIC, &startDeq);
	sortDeque();
	clock_gettime(CLOCK_MONOTONIC, &endDeq);
	double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0
	               + (endDeq.tv_nsec - startDeq.tv_nsec) / 1000.0;

	std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vector.size()
	          << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
	          << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}