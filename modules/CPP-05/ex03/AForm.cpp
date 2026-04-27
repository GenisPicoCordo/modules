#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//Constructors and Destructor
AForm::AForm() : _name("DefaultName"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, const int &sGrade, const int &eGrade): _name(name), _isSigned(false), _signGrade(sGrade), _execGrade(eGrade) {
	if (sGrade < 1 || eGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (sGrade > 150 || eGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()) {
	*this = other;
}

AForm::~AForm(){}

//Operator overloads
AForm &AForm::operator=(const AForm &other) {
	if (this != &other){
		this->_isSigned = other.getSignedStatus();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os , const AForm &Aform) {
	return (os << Aform.getSignedStatus() << " form has a signed status of " << Aform.getSignedStatus()
	<< ", a sign Grade of " << Aform.getSignGrade() << " and an exec grade of " << Aform.getExecGrade());
}

//Getters and Setters
const std::string &AForm::getName() const {
	return (this->_name);	
}

const bool &AForm::getSignedStatus() const {
	return (this->_isSigned);
}

const int &AForm::getSignGrade() const {
	return (this->_signGrade);
}

const int &AForm::getExecGrade() const {
	return (this->_execGrade);
}

//Functions
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	this->signForm(bureaucrat);
}

void AForm::signForm(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade()){
		if (this->_isSigned == true){
			throw AForm::IsAlreadySigned();
		}
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	} else
		throw Bureaucrat::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!this->_isSigned) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > _execGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->doExecute();
}

AForm *AForm::createForm(const std::string &name, const std::string &target) {
	AForm *form;

	form = NULL;
	form = ShrubberyCreationForm::createForm(form, name, target);
	form = RobotomyRequestForm::createForm(form, name, target);
	form = PresidentialPardonForm::createForm(form, name, target);

	return (form);
}

//Exception messages

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high! (Must be between 1 and 150)";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low! (Must be between 1 and 150)";
}

const char *AForm::IsAlreadySigned::what() const throw() {
	return "Form is already signed!!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed! (cannot execute unsigned forms)";
}

const char *AForm::InvalidFormException::what() const throw() {
	return "Form has not a valid type! (accepted types: 'shrubbery creation', 'robotomy request', 'presidential pardon')";
}
