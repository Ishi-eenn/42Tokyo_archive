#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
  private:
    static const std::string kFormName;
    static const unsigned int kGradeForSign = 72;
    static const unsigned int kGradeForExecute = 45;
    std::string target_;

    RobotomyRequestForm();
    void executeEachForm(Bureaucrat const &bureaucrat) const;

  public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &r);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
    ~RobotomyRequestForm();

    const std::string &getTarget() const;
    void execute(Bureaucrat const &bureaucrat) const;
};

#endif
