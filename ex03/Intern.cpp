// Copyright (c) 2025 by Abdelkader Benajiba

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>

Intern::Intern() {
  std::cout << "Intern constructed" << std::endl;
}

Intern::Intern(const Intern &other) {
  std::cout << "Intern copied" << std::endl;
  *this = other;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "Intern assigned" << std::endl;
  if (this != &other) {
    // Copy fields here
  }
  return *this;
}

Intern::~Intern() {
  std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget) {
  std::string formNames[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };
  int formIndex = -1;
  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      formIndex = i;
      break;
    }
  }

  AForm* newForm = NULL;
  switch (formIndex) {
    case 0:
      newForm = this->_makeShrubbery(formTarget);
      break;
    case 1:
      newForm = this->_makeRobotomyRequest(formTarget);
      break;
    case 2:
      newForm = this->_makePresidentialPardon(formTarget);
      break;
    default:
      std::cerr << "Intern does not know how to make form: " << formName << std::endl;
      return NULL;
  }
  std::cout << "Intern creates " << formName << std::endl;
  return newForm;
}

AForm* Intern::_makePresidentialPardon(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::_makeShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::_makeRobotomyRequest(const std::string &target) {
  return new RobotomyRequestForm(target);
}
