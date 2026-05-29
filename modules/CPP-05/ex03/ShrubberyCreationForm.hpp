#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

# define OPEN_IERROR "Error: unable to open input file"
# define GEN_IERROR "Error: general error while input file handling"
# define OPEN_OERROR "Error: unable to open output file"
# define GEN_OERROR "Error: general error while output file handling"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(const std::string &target);
		virtual ~ShrubberyCreationForm();

		//Operator Overloads
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		//Getters and Setters
		const std::string getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
