// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
  public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int &grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade(void);  // grade--
    void decrementGrade(void);  // grade++

    // Exeptions
    class GradeTooHighException : public std::exception {
    public:
      virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
      virtual const char *what() const throw();
    };

  private:
    const std::string name;
    int grade;  // 150 -> 1
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif  //  BUREAUCRAT_HPP
