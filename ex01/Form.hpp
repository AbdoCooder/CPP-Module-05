// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
  public:
    Form(const std::string &name, const int &gradeToSign, const int &gradeToExec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    const std::string getName(void)         const;
    int               getGradeToSign(void)  const;
    int               getGradeToExec(void)  const;
    bool              getIsSigned(void)     const;
    void              beSigned(const Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif //  FORM_HPP
