#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade_(kLowestGrade) {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : name_(name) {
  ThrowGradeException(grade);
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.getName()), grade_(bureaucrat.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  if (this != &bureaucrat)
    grade_ = bureaucrat.getGrade();

  return *this;
}

const std::string &Bureaucrat::getName() const {
  return name_;
}

unsigned int Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::incrementGrade() {
  ThrowGradeException(grade_ - 1);
  grade_--;
}

void Bureaucrat::decrementGrade() {
  ThrowGradeException(grade_ + 1);
  grade_++;
}

unsigned int Bureaucrat::getHighestGrade() {
  return kHighestGrade;
}

unsigned int Bureaucrat::getLowestGrade() {
  return kLowestGrade;
}

void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    throw;
  }
}

void Bureaucrat::executeForm(const AForm &form) const {
  try {
    form.execute(*this);
    std::cout << getName() << " execute " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << getName() << " failed to execute => " << e.what() << std::endl;
  }
}

void Bureaucrat::ThrowGradeException(const unsigned int grade) const {
  if (grade < kHighestGrade)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > kLowestGrade)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::logic_error("Error: Grade is too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::logic_error("Error: Grade is too low") {}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & bureaucrat)
{
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
  return (os);
}
