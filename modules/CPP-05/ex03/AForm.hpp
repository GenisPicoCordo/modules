#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm {
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

		class GradeTooLowException : std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

		class IsAlreadySigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InvalidFormException : public std::exception {
			public:
				const char *what() const throw();
		};
		
		//Constructors and Destructor
		AForm();
		AForm(const std::string &name, const int &sGrade, const int &eGrade);
		AForm(const AForm &other);
		virtual ~AForm();

		//Operator overloads
		AForm &operator=(const AForm &other);

		//Getters and Setters
		const std::string &getName() const;
		const bool &getSignedStatus() const;
		const int &getSignGrade() const;
		const int &getExecGrade() const;

		//Functions
		void beSigned(const Bureaucrat &bureaucrat);
		void signForm(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

		virtual void doExecute() const = 0;
		static AForm *createForm(const std::string &name, const std::string &target);
};

std::ostream &operator<<(std::ostream &str, const AForm &form);

#endif
