#include "Bureaucrat.hpp"
#include "Form.hpp"

//Constructors and Destructor
Form::Form() : _name("DefaultName"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &name, const int &sGrade, const int &eGrade) : _name(name), _isSigned(false), _signGrade(sGrade), _execGrade(eGrade) {
	if (sGrade < 1 || eGrade < 1)
		throw Form::GradeTooHighException();
	else if (sGrade > 150 || eGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()) {
	*this = other;
}

Form::~Form() {}

//Operator overloads
Form &Form::operator=(const Form &other) {
	if (this != &other){
		this->_isSigned = other.getSignedStatus();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os , const Form &form) {
	return (os << form.getSignedStatus() << " form has a signed status of " << form.getSignedStatus()
	<< ", a sign Grade of " << form.getSignGrade() << " and an exec grade of " << form.getExecGrade());
}

//Getters and Setters
const std::string &Form::getName() const {
	return (this->_name);	
}

const bool &Form::getSignedStatus() const { 
	return (this->_isSigned);
}

const int &Form::getSignGrade() const {
	return (this->_signGrade);
}

const int &Form::getExecGrade() const {
	return (this->_execGrade);
}

//Functions
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade()) {
		if (this->_isSigned == true){
			throw Form::IsAlreadySigned();
		}
		this->_isSigned = true;
	}
	else
		throw Form::GradeTooLowException();
}

// Exception messages
const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high! (Must be between 1 and 150)";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low! (Must be between 1 and 150)";
}

const char *Form::IsAlreadySigned::what() const throw() {
	return "Form is already signed!!";
}