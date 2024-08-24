#include "Form.hpp"

Form::Form() : grade_for_sign_(Bureaucrat::getLowestGrade()), grade_for_execute_(Bureaucrat::getLowestGrade()) {}

Form::Form(const std::string &name, const unsigned int grade_for_sign, const unsigned int grade_for_execute) : name_(name), is_signed_(false), grade_for_sign_(grade_for_sign), grade_for_execute_(grade_for_execute) {
  ThrowGradeException(grade_for_sign);
  ThrowGradeException(grade_for_execute);
}

Form::Form(const Form &form) : name_(form.getName()), is_signed_(form.getIsSigned()), grade_for_sign_(form.getGradeForSign()), grade_for_execute_(form.getGradeForExecute()) {}

Form::~Form() {}

Form &Form::operator=(const Form &form) {
  if (this != &form)
    is_signed_ = form.getIsSigned();

  return *this;
}

const std::string &Form::getName() const {
  return name_;
}

bool Form::getIsSigned() const {
  return is_signed_;
}

unsigned int Form::getGradeForSign() const {
  return grade_for_sign_;
}

unsigned int Form::getGradeForExecute() const {
  return grade_for_execute_;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_for_sign_) {
    Form::GradeTooLowException();
  }
  is_signed_ = true;
}

void Form::ThrowGradeException(const unsigned int grade) const {
  if (grade < Bureaucrat::getHighestGrade()) {
    Form::GradeTooHighException();
  } else if (grade > Bureaucrat::getLowestGrade()) {
    Form::GradeTooLowException();
  }
}

void Form::GradeTooHighException() const {
  throw Bureaucrat::GradeTooHighException();
}

void Form::GradeTooLowException() const {
  throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form info:" << std::endl;
  os << "    Form name: " << form.getName() << std::endl;
  os << "    Grade for sign: " << form.getGradeForSign() << std::endl;
  os << "    Grade for execute: " << form.getGradeForExecute() << std::endl;
  os << "    Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
  return os;
}
