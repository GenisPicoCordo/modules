#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm();
		const std::string _target;

	public:
		//Constructors and Destructor
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

		//Operator Overloads
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		//Getters and Setters
		const std::string &getTarget() const;

		//Functions
		void doExecute() const;
};

#endif
