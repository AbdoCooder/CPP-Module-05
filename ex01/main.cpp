#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

  // --- Test 1: Form Creation ---
  std::cout << "--- Test 1: Form Creation ---" << std::endl;
  
  // Test 1a: Valid Form
  try {
    Form f1("28B", 50, 25);
    std::cout << f1 << std::endl;
  } catch(std::exception & e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  // Test 1b: Grade Too High
  try {
    Form f2("Invalid", 0, 25);
    std::cout << "THIS SHOULD NOT PRINT." << std::endl;
  } catch(std::exception & e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  // Test 1c: Grade Too Low
  try {
    Form f3("Invalid", 50, 151);
    std::cout << "THIS SHOULD NOT PRINT." << std::endl;
  } catch(std::exception & e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  // --- Test 2: Signing Logic ---
  std::cout << "\n--- Test 2: Signing Logic ---" << std::endl;
  
  // Create Bureaucrats
  Bureaucrat arthur("Arthur", 42);
  Bureaucrat trillian("Trillian", 5);

  // Create Forms
  Form taxForm("Tax Form", 50, 25);
  Form secretPlan("Secret Plan", 10, 5);
  
  std::cout << arthur << std::endl;
  std::cout << trillian << std::endl;
  std::cout << taxForm << std::endl;
  std::cout << secretPlan << std::endl;

  // Test 2a: Successful Sign
  std::cout << "\n--- Test 2a: Arthur signs Tax Form (should succeed) ---" << std::endl;
  arthur.signForm(taxForm);
  std::cout << taxForm << std::endl; // Check if status changed

  // Test 2b: Failed Sign (Grade Too Low)
  std::cout << "\n--- Test 2b: Arthur signs Secret Plan (should fail) ---" << std::endl;
  arthur.signForm(secretPlan);
  std::cout << secretPlan << std::endl; // Check that status did NOT change

  // Test 2c: Successful Sign (High Grade Bureaucrat)
  std::cout << "\n--- Test 2c: Trillian signs Secret Plan (should succeed) ---" << std::endl;
  trillian.signForm(secretPlan);
  std::cout << secretPlan << std::endl; // Check if status changed

  // Test 2d: Signing an already-signed form
  std::cout << "\n--- Test 2d: Trillian signs Secret Plan again ---" << std::endl;
  trillian.signForm(secretPlan); // Should just print success again
  std::cout << secretPlan << std::endl; // Status should still be signed

  return 0;
}
