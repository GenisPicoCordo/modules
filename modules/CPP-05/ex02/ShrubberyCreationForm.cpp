#include "ShrubberyCreationForm.hpp"

//Constructors and Destructor

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

//Operator overloads
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	(void)other;
	return (*this);
}

//Getters and Setters
const std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void ShrubberyCreationForm::doExecute() const {
	std::ofstream outputFile((_target + "_shrubbery").c_str());

	if (outputFile.fail()) {
		std::cerr << "Error: Failed to open file for writing." << std::endl;
		return;
	}
	int treeType = std::rand() % 3;

	switch (treeType) {
		case 0:
			outputFile << "       _-_" << std::endl;
			outputFile << "    /~~   ~~\\" << std::endl;
			outputFile << " /~~         ~~\\" << std::endl;
			outputFile << "{               }" << std::endl;
			outputFile << " \\  _-     -_  /" << std::endl;
			outputFile << "   ~  \\ //  ~" << std::endl;
			outputFile << " _- - | | _- _" << std::endl;
			outputFile << "   -  | |   -" << std::endl;
			outputFile << "      | |" << std::endl;
			outputFile << "      | |" << std::endl;
			outputFile << "      ---" << std::endl;
			break;
		case 1:
			outputFile << "      *" << std::endl;
			outputFile << "     ***" << std::endl;
			outputFile << "    *****" << std::endl;
			outputFile << "   *******" << std::endl;
			outputFile << "  *********" << std::endl;
			outputFile << " ***********" << std::endl;
			outputFile << "     |||" << std::endl;
			outputFile << "     |||" << std::endl;
			break;
		case 2:
			outputFile << "      ^" << std::endl;
			outputFile << "     ^^^" << std::endl;
			outputFile << "    ^^^^^" << std::endl;
			outputFile << "   ^^^^^^^" << std::endl;
			outputFile << "  ^^^^^^^^^" << std::endl;
			outputFile << " ^^^^^^^^^^^" << std::endl;
			outputFile << "     |||" << std::endl;
			outputFile << "     |||" << std::endl;
			break;
	}
	outputFile.close();
	std::cout << "🌲 Shrubbery successfully planted in " << _target << "_shrubbery 🌲" << std::endl;
}

