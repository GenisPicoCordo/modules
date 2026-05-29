#include "Bureaucrat.hpp"
#include "AForm.hpp"

//Constructors and Destructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

//Operator overloads
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".");
}

//Getters and Setters
const std::string &Bureaucrat::getName() const {
	return (this->_name);
}

const int &Bureaucrat::getGrade() const {
	return (this->_grade);
}

// Grade modification
void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << this->getName() << " couldn't sign "
				  << form.getName() << " because grade is too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << this->_name << " couldn't execute " << form.getName()
				  << " because: " << e.what() << std::endl;
	}
}

//Exception messages
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! (Must be between 1 and 150)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! (Must be between 1 and 150)";
}
