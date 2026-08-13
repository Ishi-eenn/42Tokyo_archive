#include "AForm.hpp"

AForm::AForm() : grade_for_sign_(Bureaucrat::getLowestGrade()), grade_for_execute_(Bureaucrat::getLowestGrade()) {}

AForm::AForm(const std::string &name, const unsigned int grade_for_sign, const unsigned int grade_for_execute) : name_(name), is_signed_(false), grade_for_sign_(grade_for_sign), grade_for_execute_(grade_for_execute) {
  ThrowGradeException(grade_for_sign);
  ThrowGradeException(grade_for_execute);
}

AForm::AForm(const AForm &form) : name_(form.getName()), is_signed_(form.getIsSigned()), grade_for_sign_(form.getGradeForSign()), grade_for_execute_(form.getGradeForExecute()) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &form) {
  if (this != &form)
    is_signed_ = form.getIsSigned();

  return *this;
}

AForm::NotSignedException::NotSignedException() : std::logic_error("Error: not signed") {}

const std::string &AForm::getName() const {
  return name_;
}

bool AForm::getIsSigned() const {
  return is_signed_;
}

unsigned int AForm::getGradeForSign() const {
  return grade_for_sign_;
}

unsigned int AForm::getGradeForExecute() const {
  return grade_for_execute_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_for_sign_) {
    AForm::GradeTooLowException();
  }
  is_signed_ = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const {
  if (!is_signed_)
    throw AForm::NotSignedException();

  if (bureaucrat.getGrade() > grade_for_execute_)
    AForm::GradeTooLowException();

  executeEachForm(bureaucrat);
}

void AForm::ThrowGradeException(const unsigned int grade) const {
  if (grade < Bureaucrat::getHighestGrade()) {
    AForm::GradeTooHighException();
  } else if (grade > Bureaucrat::getLowestGrade()) {
    AForm::GradeTooLowException();
  }
}

void AForm::GradeTooHighException() const {
  throw Bureaucrat::GradeTooHighException();
}

void AForm::GradeTooLowException() const {
  throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form info:" << std::endl;
  os << "    Form name: " << form.getName() << std::endl;
  os << "    Grade for sign: " << form.getGradeForSign() << std::endl;
  os << "    Grade for execute: " << form.getGradeForExecute() << std::endl;
  os << "    Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
  return os;
}
