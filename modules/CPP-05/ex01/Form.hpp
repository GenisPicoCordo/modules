#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		//Exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();	
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class IsAlreadySigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		//Constructors and Destructor
		Form();
		Form(const std::string &name, const int &sGrade, const int &eGrade);
		Form(const Form &other);
		~Form();

		//Operator overloads
		Form &operator=(const Form &other);

		//Getters and Setters
		const std::string &getName() const;
		const bool &getSignedStatus() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;

		//Functions
		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &str, const Form &form);

#endif