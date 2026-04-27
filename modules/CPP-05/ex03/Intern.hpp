#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern {
	private:
		//Function pointer type for form creation
		typedef AForm *(*FormCreator)(const std::string &);

		//Struct to associate form names with creation functions
		struct FormType {
			std::string name;
			FormCreator creator;
		};

		// Array of form types
		static FormType formTypes[3];

		//Static creator functions
		static AForm *createShrubberyForm(const std::string &target);
		static AForm *createRobotomyForm(const std::string &target);
		static AForm *createPresidentialForm(const std::string &target);

	public:
		//Exception classes
		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
		//Constructors and destructor
		Intern();
		Intern(const Intern &other);
		~Intern();

		//Operator overloads
		Intern &operator=(const Intern &other);

		//Functions
		AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
