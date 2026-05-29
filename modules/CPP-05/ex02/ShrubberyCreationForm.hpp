#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();

		//Operator Overloads
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		//Getters and Setters
		const std::string getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
