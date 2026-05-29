#include "PresidentialPardonForm.hpp"

//Constructors and Destructor

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

//Operator overloads
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	(void)other;
	return (*this);
}

//Getters and Setters
const std::string PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void PresidentialPardonForm::doExecute() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

