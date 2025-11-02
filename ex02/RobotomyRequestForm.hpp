// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const & executor) const;

    class FormNotSignedException : public std::exception {
      public: 
        virtual const char* what() const throw();
    };

  private:
    std::string target;
};

#endif //  ROBOTOMYREQUESTFORM_HPP
