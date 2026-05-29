#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

static void header(const std::string& t) {
    std::cout << "\n========== " << t << " ==========\n";
}

int main() {
    Intern      someRandomIntern;
    Bureaucrat  boss("Boss", 1);
    Bureaucrat  mid("Mid", 50);
    Bureaucrat  low("Low", 150);

    AForm* f = 0;

    // 1) ROBOTOMY
    header("ROBOTOMY: create -> sign -> execute -> delete (aunque haya excepciones)");
    try {
        f = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "Created: " << f->getName() << "\n";

        // Usa los métodos del Bureaucrat para que impriman y/o manejen excepciones
        low.signForm(*f);   // fallará (grade muy bajo)
        mid.signForm(*f);   // puede firmar (50 <= 72)
        boss.executeForm(*f); // puede ejecutar (1 <= 45)

        delete f;
        f = 0;
    } catch (const std::exception& e) {
        delete f;
        f = 0;
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 2) SHRUBBERY
    header("SHRUBBERY: create -> sign -> execute (crea <target>_shrubbery) -> delete");
    try {
        f = someRandomIntern.makeForm("shrubbery creation", "Home");
        std::cout << "Created: " << f->getName() << "\n";

        low.signForm(*f);     // normalmente falla (150 > 145)
        boss.signForm(*f);    // firma
        mid.executeForm(*f);  // ejecuta (50 <= 137) -> crea Home_shrubbery

        delete f;
        f = 0;
    } catch (const std::exception& e) {
        delete f;
        f = 0;
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 3) PRESIDENTIAL PARDON
    header("PARDON: create -> sign -> execute -> delete");
    try {
        f = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << "Created: " << f->getName() << "\n";

        mid.signForm(*f);   // falla (50 > 25)
        boss.signForm(*f);  // firma
        boss.executeForm(*f); // ejecuta (1 <= 5)

        delete f;
        f = 0;
    } catch (const std::exception& e) {
        delete f;
        f = 0;
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    // 4) FORM NO EXISTE
    header("UNKNOWN FORM: debe lanzar y NO filtrar memoria");
    try {
        f = someRandomIntern.makeForm("shrubbery creations", "WrongName"); // typo a propósito
        // Si por alguna razón devolviera algo, lo limpiamos:
        delete f;
        f = 0;
    } catch (const std::exception& e) {
        delete f; // por seguridad
        f = 0;
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\nTIP: si ejecutaste SHRUBBERY con target 'Home', mira el archivo: Home_shrubbery\n";
    return 0;
}