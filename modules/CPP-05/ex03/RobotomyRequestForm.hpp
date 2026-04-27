#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(const std::string &target);
		virtual ~RobotomyRequestForm();

		//Operator Overloads
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		//Getters and Setters
		const std::string getTarget() const;

		//Functions
		void doExecute() const;
		static AForm *createForm(AForm *form, const std::string &name, const std::string &target);
};

#endif
