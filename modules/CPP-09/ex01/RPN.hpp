#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int, std::list<int> > _stack;
		
		bool isOperator(char c) const;
		int  performOperation(int a, int b, char op) const;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void calculate(const std::string &expression);
};

#endif