#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

const std::string RobotomyRequestForm::kFormName = "Robotomy Request";

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(kFormName, kGradeForSign, kGradeForExecute), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : AForm(r.getName(), r.getGradeForSign(), r.getGradeForExecute()), target_(r.getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r) {
  if (this != &r) {
    AForm::operator=(r);
    target_ = r.getTarget();
  }

  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const {
  return target_;
}

static bool IsRobotomized() {
  const unsigned int  random_int = std::rand();
  static unsigned int number = random_int % 2;

  number ^= 1;
  return number == 1;
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
  AForm::execute(bureaucrat);
}

void RobotomyRequestForm::executeEachForm(Bureaucrat const &bureaucrat) const {
  std::cout << bureaucrat.getName() << ": " << target_;
  if (IsRobotomized()) {
    std::cout << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << " Failed to robotomized." << std::endl;
  }
}
