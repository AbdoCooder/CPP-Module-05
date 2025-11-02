// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const & executor) const;

    class FormNotSignedException : public std::exception {
      public: 
        virtual const char* what() const throw();
    };

  private:
    std::string target;
};

#endif //  PRESIDENTIALPARDONFORM_HPP
