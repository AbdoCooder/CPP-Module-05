// Copyright (c) 2025 by Abdelkader Benajiba

#include "Form.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), isSigned(false), gradeToSign(150), gradeToExec(150) {
  std::cout << "Form constructed" << std::endl;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
  if (gradeToSign < 1 || gradeToExec < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExec > 150) {
    throw Form::GradeTooLowException();
  }
  this->isSigned = false;
  std::cout << "Form constructed" << std::endl;
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
  this->isSigned = other.isSigned;
  std::cout << "Form copied" << std::endl;
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  std::cout << "Form assigned" << std::endl;
  return *this;
}

Form::~Form() {
  std::cout << "Form destroyed" << std::endl;
}

const std::string Form::getName(void) const {
  return name;
}

bool  Form::getIsSigned(void) const {
  return isSigned;
}

int   Form::getGradeToSign(void) const {
  return gradeToSign;
}

int   Form::getGradeToExec(void) const {
  return gradeToExec;
}

const char* Form::GradeTooHighException::what(void) const throw() {
  return "the grade is too high.";
}

const char* Form::GradeTooLowException::what(void) const throw() {
  return "the grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << "Form : " + f.getName() << std::endl;
  out << "GradeToSign : " << f.getGradeToSign() << std::endl;
  out << "GradeToExec : " << f.getGradeToExec() << std::endl;
  if (f.getIsSigned()) {
    out << "The Form is signed!" << std::endl;
  } else {
    out << "The Form is Not signed!" << std::endl;
  }
  return out;
}

void  Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= gradeToSign) {
    isSigned = true;
  } else {
    throw Form::GradeTooLowException();
  }
}
