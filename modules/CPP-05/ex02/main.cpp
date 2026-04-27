#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

static void safeSign(Bureaucrat& b, AForm& f) {
    try { 
        b.signForm(f); 
    }
    catch (const std::exception& e) { 
        std::cout << "SIGN EX: " << e.what() << "\n"; 
    }
}

static void safeExec(Bureaucrat& b, AForm& f) {
    try { 
        b.executeForm(f); 
    }
    catch (const std::exception& e) { 
        std::cout << "EXEC EX: " << e.what() << "\n"; 
    }
}

int main() {
    Bureaucrat b2("Noemi", 145);  // firma shrub OK, pero NO ejecuta shrub (137)
    Bureaucrat b3("Eren", 100);   // ejecuta shrub OK
    Bureaucrat boss("Genis", 1);  // ejecuta todo

    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << RED << "\n--- SHRUB: firmar una vez, ejecutar con quien puede" << RESET << std::endl;
    safeSign(b2, shrub);      // queda firmado
    safeExec(b2, shrub);      // fallará (grade too low)
    safeExec(b3, shrub);      // ✅ crea Home_shrubbery

    std::cout << RED << "\n--- ROBO: firmar y ejecutar con boss" << RESET << std::endl;
    safeSign(b3, robo);       // b3=100 NO puede firmar robo (72) -> fallará
    safeSign(boss, robo);     // ✅ firma
    safeExec(boss, robo);     // ✅ 50/50
    safeExec(boss, robo);     // ✅ repite

    std::cout << RED << "\n--- PARDON: firmar y ejecutar con boss" << RESET << std::endl;
    safeSign(boss, pardon);   // ✅
    safeExec(boss, pardon);   // ✅

    std::cout << RED << "\nMira el archivo: cat Home_shrubbery" << RESET << std::endl;
    return 0;
}