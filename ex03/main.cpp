#include <iostream>
#include <cstdlib> // For srand()
#include <ctime>   // For time()

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {
    // Seed random for Robotomy
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);

    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* invalid;

    std::cout << "\n--- Test 1: Robotomy Request (from PDF) ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
    }

    std::cout << "\n--- Test 2: Shrubbery Creation ---" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
    }

    std::cout << "\n--- Test 3: Presidential Pardon ---" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
    }

    std::cout << "\n--- Test 4: Invalid Form ---" << std::endl;
    invalid = someRandomIntern.makeForm("request for a vacation", "Intern");
    if (invalid) {
        std::cout << "ERROR: Invalid form was created!" << std::endl;
    }

    std::cout << "\n--- Cleaning up memory ---" << std::endl;
    delete rrf;
    delete scf;
    delete ppf;
    delete invalid;

    return 0;
}
