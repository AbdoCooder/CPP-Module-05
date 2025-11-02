// Copyright (c) 2025 by Abdelkader Benajiba

#include "AForm.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(150), gradeToExec(150) {
  std::cout << "AForm constructed" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
  if (gradeToSign < 1 || gradeToExec < 1) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExec > 150) {
    throw AForm::GradeTooLowException();
  }
  this->isSigned = false;
  std::cout << "AForm constructed" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
  this->isSigned = other.isSigned;
  std::cout << "AForm copied" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  std::cout << "AForm assigned" << std::endl;
  return *this;
}

AForm::~AForm() {
  std::cout << "AForm destroyed" << std::endl;
}

const std::string AForm::getName(void) const {
  return name;
}

bool  AForm::getIsSigned(void) const {
  return isSigned;
}

int   AForm::getGradeToSign(void) const {
  return gradeToSign;
}

int   AForm::getGradeToExec(void) const {
  return gradeToExec;
}

const char* AForm::GradeTooHighException::what(void) const throw() {
  return "the grade is too high.";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
  return "the grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << "AForm : " + f.getName() << std::endl;
  out << "GradeToSign : " << f.getGradeToSign() << std::endl;
  out << "GradeToExec : " << f.getGradeToExec() << std::endl;
  if (f.getIsSigned()) {
    out << "The AForm is signed!" << std::endl;
  } else {
    out << "The AForm is Not signed!" << std::endl;
  }
  return out;
}

void  AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= gradeToSign) {
    isSigned = true;
  } else {
    throw AForm::GradeTooLowException();
  }
}
