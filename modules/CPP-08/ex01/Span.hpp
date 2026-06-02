#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>
# include <climits>

class Span {
	private:
		unsigned int _size;
		std::vector<int> _numbers;

	public:
		class OversizeException : public std::exception {
			public:
				const char *what() const throw();
		};

		class NoNumbersException : public std::exception {
			public:
				const char *what() const throw();
		};

		Span();
		Span(const unsigned int &n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(const int &number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addNumbersRange(Iterator begin, Iterator end) {
			for (Iterator it = begin; it != end; ++it) {
				this->addNumber(*it);
			}
		}
};

#endif