#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("DefaultName"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _signGrade(other._signGrade),
	  _execGrade(other._execGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSignedStatus() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (_isSigned)
		throw AForm::IsAlreadySigned();

	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();

	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned)
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();

	doExecute();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << form.getName()
	   << ", signed: " << form.getSignedStatus()
	   << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecGrade();
	return os;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high! Must be between 1 and 150";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low! Must be between 1 and 150";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

const char *AForm::IsAlreadySigned::what() const throw() {
	return "Form is already signed";
}