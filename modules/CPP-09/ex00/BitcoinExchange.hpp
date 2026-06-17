#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>

class	BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		bool isValidDate(const std::string &date) const;
		std::string trim(const std::string &str) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		bool loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
};

#endif