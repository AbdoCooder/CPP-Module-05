#include <iostream>
#include <cstdlib> // For srand()
#include <ctime>   // For time()

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    // --- IMPORTANT: Seed the random number generator ---
    // This is required for RobotomyRequestForm to be random
    std::srand(std::time(NULL));

    try {
        // --- 1. Setup ---
        std::cout << "--- 1. CREATING ACTORS ---" << std::endl;
        Bureaucrat highGrade("Zaphod", 1);
        Bureaucrat midGrade("Arthur", 70);
        Bureaucrat lowGrade("Marvin", 140);

        std::cout << highGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << lowGrade << std::endl;
        
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("Bender");
        PresidentialPardonForm pardonForm("Ford");

        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;

        // --- 2. Test: Execute without signing ---
        std::cout << "\n--- 2. TEST: EXECUTE UNSIGNED FORM (should fail) ---" << std::endl;
        highGrade.executeForm(shrubForm); // Should fail (not signed)

        // --- 3. Test: Low grade sign & execute ---
        std::cout << "\n--- 3. TEST: LOW GRADE BUREAUCRAT ---" << std::endl;
        lowGrade.signForm(shrubForm);     // Should succeed (140 <= 145)
        lowGrade.executeForm(shrubForm);  // Should fail (140 > 137)

        // --- 4. Test: Mid grade sign & execute ---
        std::cout << "\n--- 4. TEST: MID GRADE BUREAUCRAT ---" << std::endl;
        midGrade.signForm(roboForm);    // Should succeed (70 <= 72)
        midGrade.executeForm(roboForm); // Should fail (70 > 45)

        // --- 5. Test: High grade sign & execute (ALL) ---
        std::cout << "\n--- 5. TEST: HIGH GRADE BUREAUCRAT ---" << std::endl;
        
        std::cout << "\n--- PARDON FORM ---" << std::endl;
        highGrade.signForm(pardonForm);
        highGrade.executeForm(pardonForm);

        std::cout << "\n--- ROBOTOMY FORM (x4 for randomness) ---" << std::endl;
        // Note: roboForm is already signed by midGrade
        highGrade.executeForm(roboForm); 
        highGrade.executeForm(roboForm); 
        highGrade.executeForm(roboForm); 
        highGrade.executeForm(roboForm); 

        std::cout << "\n--- SHRUBBERY FORM ---" << std::endl;
        // Note: shrubForm is already signed by lowGrade
        highGrade.executeForm(shrubForm);
        std::cout << "Check your directory for a file named 'home_shrubbery'" << std::endl;

    } catch(std::exception & e) {
        std::cerr << "Unhandled exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
