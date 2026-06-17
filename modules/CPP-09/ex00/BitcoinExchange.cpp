#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		this->_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str) const 
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string &date) const 
{
	if (date.length() != 10) 
		return false;
	if (date[4] != '-' || date[7] != '-') 
		return false;

	for (int i = 0; i < 10; i++) 
	{
		if (i == 4 || i == 7) 
			continue;
		if (!std::isdigit(date[i])) 
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2008 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Validación de días por mes
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) 
			return false;
	} else if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	return true;
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line); // Saltar header: date,exchange_rate0
	while (std::getline(file, line)) {
		size_t pos = line.find(',');
		if (pos != std::string::npos) {
			std::string date = line.substr(0, pos);
			float rate = static_cast<float>(std::atof(line.substr(pos + 1).c_str()));
			_data[date] = rate;
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // Saltar header: date | value
	while (std::getline(file, line)) 
	{
		if (line.empty()) 
			continue;

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		char *endptr;
		double value = std::strtod(valStr.c_str(), &endptr);
		if (*endptr != '\0' && !std::isspace(*endptr)) {
			std::cout << "Error: bad input => " << valStr << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
		} else if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
		} else {
			// Buscar la fecha o la anterior más cercana
			std::map<std::string, float>::iterator it = _data.lower_bound(date);
			
			if (it == _data.end() || (it->first != date && it != _data.begin())) {
				if (it->first != date) --it;
			}
			
			// Validar que la fecha encontrada no sea posterior a la buscada si es el primer elemento
			if (it == _data.end() || (it == _data.begin() && it->first > date)) {
				std::cout << "Error: date too early => " << date << std::endl;
			} else {
				std::cout << date << " => " << valStr << " = " << (value * it->second) << std::endl;
			}
		}
	}
	file.close();
}