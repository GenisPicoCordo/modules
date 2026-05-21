#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

		class IsAlreadySigned : public std::exception {
			public:
				const char *what() const throw();
		};

		AForm();
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

		virtual void doExecute() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif