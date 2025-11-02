// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const & executor) const;

    class FormNotSignedException : public std::exception {
      public: 
        virtual const char* what() const throw();
    };

  private:
    std::string target;
};

#endif //  SHRUBBERYCREATIONFORM_HPP
