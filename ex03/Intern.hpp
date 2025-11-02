// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
  public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &formTarget);
    AForm* _makePresidentialPardon(const std::string &target);
    AForm* _makeShrubbery(const std::string &target);
    AForm* _makeRobotomyRequest(const std::string &target);
};

#endif //  INTERN_HPP
