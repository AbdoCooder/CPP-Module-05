// Copyright (c) 2025 by Abdelkader Benajiba

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void drawTree(const std::string &target) {
  std::ofstream fileOutput((target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
  if (fileOutput.fail()) {
    std::cerr << "Error: Can't create the file "<< (target + "_shrubbery").c_str() << "\n";
    return;
  }
  const char *art[] = {
      "       ccee88oo",
      "  C8O8O8Q8PoOb o8oo",
      " dOB69QO8PdUOpugoO9bD",
      "CgggbU8OU qOp qOdoUOdcb",
      "   6OuU  /p u gcoUodpP",
      "     \\\\//  /douUP",
      "       \\\\////",
      "        |||/\\",
      "        |||\\/",
      "        |||||",
      "  .....//||||\\...."
  };
  for (int i = 0; i < 11; i++) {
    fileOutput << art[i] << '\n';
  }
  fileOutput.close();
}

// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
  std::cout << "ShrubberyCreationForm constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
  std::cout << "ShrubberyCreationForm constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {
  std::cout << "ShrubberyCreationForm copied" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  std::cout << "ShrubberyCreationForm assigned" << std::endl;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

const char* ShrubberyCreationForm::FormNotSignedException::what() const throw() {
  return "ShrubberyCreationForm Form can not be executed if not signed!";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  if (this->getIsSigned() == false) {
    throw ShrubberyCreationForm::FormNotSignedException();
  }
  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  }
  drawTree(this->target);
}
