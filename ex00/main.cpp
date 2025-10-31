// Copyright (c) 2025 by Abdelkader Benajiba

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    // Test 1: Valid Bureaucrat creation and getters
    std::cout << "--- Test 1: Valid Creation ---" << std::endl;
    try
    {
        Bureaucrat zaphod("Zaphod", 42);
        std::cout << zaphod << std::endl; // Tests operator<<
        std::cout << "Name: " << zaphod.getName() << std::endl;
        std::cout << "Grade: " << zaphod.getGrade() << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Test 2: Grade too high on creation
    std::cout << "\n--- Test 2: Grade Too High (Creation) ---" << std::endl;
    try
    {
        Bureaucrat invalid("HighGrade", 0); // Should throw
        std::cout << "THIS SHOULD NOT PRINT." << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Test 3: Grade too low on creation
    std::cout << "\n--- Test 3: Grade Too Low (Creation) ---" << std::endl;
    try
    {
        Bureaucrat invalid("LowGrade", 151); // Should throw
        std::cout << "THIS SHOULD NOT PRINT." << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Test 4: Valid increment and decrement
    std::cout << "\n--- Test 4: Valid Increment/Decrement ---" << std::endl;
    try
    {
        Bureaucrat arthur("Arthur", 100);
        std::cout << arthur << std::endl;
        
        arthur.incrementGrade(); // Grade becomes 99
        std::cout << "After increment: " << arthur << std::endl;
        
        arthur.decrementGrade(); // Grade becomes 100
        std::cout << "After decrement: " << arthur << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Test 5: Exception on incrementing too high
    std::cout << "\n--- Test 5: Grade Too High (Increment) ---" << std::endl;
    try
    {
        Bureaucrat boss("TheBoss", 1); // Highest grade
        std::cout << boss << std::endl;
        boss.incrementGrade(); // Should throw
        std::cout << "THIS SHOULD NOT PRINT." << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Test 6: Exception on decrementing too low
    std::cout << "\n--- Test 6: Grade Too Low (Decrement) ---" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150); // Lowest grade
        std::cout << intern << std::endl;
        intern.decrementGrade(); // Should throw
        std::cout << "THIS SHOULD NOT PRINT." << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 7: Copy and Assignment
    std::cout << "\n--- Test 7: Copy / Assignment ---" << std::endl;
    Bureaucrat original("Original", 25);
    Bureaucrat copy(original); // Copy constructor
    Bureaucrat assigned("Assigned", 77);
    
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Before assign: " << assigned << std::endl;
    
    assigned = original; // Assignment operator
    
    std::cout << "After assign: " << assigned << std::endl;

    return 0;
}
