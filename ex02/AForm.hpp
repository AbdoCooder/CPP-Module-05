// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
  public:
    AForm();
    AForm(const std::string &name, const int &gradeToSign, const int &gradeToExec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();

    const std::string getName(void)         const;
    int               getGradeToSign(void)  const;
    int               getGradeToExec(void)  const;
    bool              getIsSigned(void)     const;
    void              beSigned(const Bureaucrat &b);

    virtual void execute(Bureaucrat const & executor) const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception {
      public: 
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

  private:
    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif //  AFORM_HPP
