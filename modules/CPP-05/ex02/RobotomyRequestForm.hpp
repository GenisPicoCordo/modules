#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"


class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();

		//Operator Overloads
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		//Getters and Setters
		const std::string getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
