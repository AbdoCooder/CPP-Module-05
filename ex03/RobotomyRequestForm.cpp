// Copyright (c) 2025 by Abdelkader Benajiba

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")  {
  std::cout << "RobotomyRequestForm constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)  {
  std::cout << "RobotomyRequestForm (target) constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {
  std::cout << "RobotomyRequestForm copied" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  std::cout << "RobotomyRequestForm assigned" << std::endl;
  if (this != &other) {
    this->target = other.target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

const char* RobotomyRequestForm::FormNotSignedException::what() const throw() {
  return "RobotomyRequestForm Form can not be executed if not signed!";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  if (this->getIsSigned() == false) {
    throw RobotomyRequestForm::FormNotSignedException();
  }
  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  }
  // Noises
  std::cout << "* BZZZZT... DRIIIILL... *" << std::endl;
  if (rand() % 2 == 0) {
    // 50% chance (success)
    std::cout << this->target << " has been robotomized successfully." << std::endl;
  } else {
    // Other 50% chance (failure)
    std::cout << "The robotomy failed." << std::endl;
  }
}
