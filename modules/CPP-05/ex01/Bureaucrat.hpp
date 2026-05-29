#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// Constructors and Destructor
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		// Operator overloads
		Bureaucrat &operator=(const Bureaucrat &other);

		// Getters
		const std::string &getName() const;
		int getGrade() const;

		// Functions
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
