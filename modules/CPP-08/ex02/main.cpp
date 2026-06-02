#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include "MutantStack.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
	std::cout << RED << "----LIST test----" << RESET << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << RED << std::endl << "----VECTOR test----" << RESET << std::endl;
	{
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);  // Fixed typo: push_pushback -> push_back
		//[...]
		mstack.push_back(0);  // Changed push to push_back
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << RED << std::endl << "----MUTANT STACK test----" << RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	// Test with strings
    std::cout << RED << "\n----STRING STACK TEST----" << RESET << std::endl;
    {
        MutantStack<std::string> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("C++");
        strStack.push("Templates");
        
        std::cout << "String stack size: " << strStack.size() << std::endl;
        std::cout << "Top element: " << strStack.top() << std::endl;
        strStack.pop();
        std::cout << "After pop, top element: " << strStack.top() << std::endl;
        
        std::cout << "All strings (reverse order):" << std::endl;
        MutantStack<std::string>::reverse_iterator rit = strStack.rbegin();
        MutantStack<std::string>::reverse_iterator rite = strStack.rend();
        
        while (rit != rite) {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }
    // Copy constructor and assignment operator test
    std::cout << RED << "\n----COPY & ASSIGNMENT TEST----" << RESET << std::endl;
    {
        MutantStack<int> original;
        for (int i = 0; i < 5; i++) {
            original.push(i * 10);
        }
        
        // Test copy constructor
        MutantStack<int> copied(original);
        std::cout << "Original stack top: " << original.top() << std::endl;
        std::cout << "Copied stack top: " << copied.top() << std::endl;
        
        // Modify original, copied should remain unchanged
        original.push(999);
        std::cout << "After modification:" << std::endl;
        std::cout << "Original stack top: " << original.top() << std::endl;
        std::cout << "Copied stack top: " << copied.top() << std::endl;
        
        // Test assignment operator
        MutantStack<int> assigned;
        assigned = original;
        original.pop();
        std::cout << "After assignment and original pop:" << std::endl;
        std::cout << "Original stack top: " << original.top() << std::endl;
        std::cout << "Assigned stack top: " << assigned.top() << std::endl;
    }
    // Const iterator test
    std::cout << RED << "\n----CONST ITERATOR TEST----" << RESET << std::endl;
    {
        MutantStack<int> mstack;
        for (int i = 0; i < 5; i++) {
            mstack.push(i);
        }
        
        const MutantStack<int> constStack(mstack);
        std::cout << "Const stack content:" << std::endl;
        
        // Using const_iterator
        MutantStack<int>::const_iterator cit = constStack.begin();
        MutantStack<int>::const_iterator cite = constStack.end();
        
        while (cit != cite) {
            std::cout << *cit << std::endl;
            // Uncomment next line to test that modification fails with const_iterator
            // *cit = 100;  // Should cause compilation error
            ++cit;
        }
    }
    // Compare with standard container (list)
    std::cout << RED << "\n----COMPARISON WITH STD::LIST----" << RESET << std::endl;
    {
        MutantStack<int> mstack;
        std::list<int> mlist;
        
        // Add same elements to both
        for (int i = 0; i < 5; i++) {
            mstack.push(i);
            mlist.push_back(i);
        }
        
        std::cout << "MutantStack elements:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "List elements:" << std::endl;
        for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}