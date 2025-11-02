// Copyright (c) 2025 by Abdelkader Benajiba

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default")  {
  std::cout << "PresidentialPardonForm constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm (target) constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {
  std::cout << "PresidentialPardonForm copied" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  std::cout << "PresidentialPardonForm assigned" << std::endl;
  if (this != &other) {
    this->target = other.target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

const char* PresidentialPardonForm::FormNotSignedException::what() const throw() {
  return "PresidentialPardonForm Form can not be executed if not signed!";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  if (this->getIsSigned() == false) {
    throw PresidentialPardonForm::FormNotSignedException();
  }
  if (executor.getGrade() > this->getGradeToExec()) {
    throw AForm::GradeTooLowException();
  }
  std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
