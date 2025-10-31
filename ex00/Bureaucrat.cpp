// Copyright (c) 2025 by Abdelkader Benajiba

#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : name(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else {
    this->grade = grade;
  }
  std::cout << "Bureaucrat constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  std::cout << "Bureaucrat copied" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    grade = other.grade;
  }
  std::cout << "Bureaucrat's grade assigned (name can't change)" << std::endl;
  return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destroyed" << std::endl; }

void Bureaucrat::incrementGrade(void) {
  if (grade < 2) {
    throw Bureaucrat::GradeTooHighException();
  } else {
    grade--;
  }
}

void Bureaucrat::decrementGrade(void) {
  if (grade > 149) {
    throw Bureaucrat::GradeTooLowException();
  } else {
    grade++;
  }
}

std::string Bureaucrat::getName(void) const { return name; }

int Bureaucrat::getGrade(void) const { return grade; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade is too low.";
}
