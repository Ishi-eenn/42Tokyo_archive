#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const std::string PresidentialPardonForm::kFormName = "Presidential Pardon";

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(kFormName, kGradeForSign, kGradeForExecute), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p.getName(), p.getGradeForSign(), p.getGradeForExecute()), target_(p.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p) {
  if (this != &p) {
    AForm::operator=(p);
    target_ = p.getTarget();
  }

  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const {
  return target_;
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const {
  AForm::execute(bureaucrat);
}

void PresidentialPardonForm::executeEachForm(Bureaucrat const &bureaucrat) const {
  std::cout << bureaucrat.getName() << ": " << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
