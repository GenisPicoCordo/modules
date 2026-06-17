#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool	RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::performOperation(int a, int b, char op) const
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') {
		if (b == 0) {
			std::cerr << "Error: division by zero." << std::endl;
			std::exit(1);
		}
		return a / b;
	}
	return 0;
}

void	RPN::calculate(const std::string &expression) 
{
	for (size_t i = 0; i < expression.length(); i++) {
		char c = expression[i];

		if (std::isspace(c))
			continue;

		if (std::isdigit(c)) {
			// El subject dice que los números siempre son < 10 (un solo dígito)
			_stack.push(c - '0');
		} 
		else if (isOperator(c)) {
			if (_stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			_stack.push(performOperation(a, b, c));
		} 
		else {
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (_stack.size() != 1) {
		std::cerr << "Error" << std::endl;
	} else {
		std::cout << _stack.top() << std::endl;
	}
}