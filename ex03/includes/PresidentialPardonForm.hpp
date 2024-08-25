#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
  private:
    static const std::string kFormName;
    static const unsigned int kGradeForSign = 25;
    static const unsigned int kGradeForExecute = 5;
    std::string target_;

    PresidentialPardonForm();
    void executeEachForm(Bureaucrat const &bureaucrat) const;

  public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &p);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
    ~PresidentialPardonForm();

    const std::string &getTarget() const;
    void execute(Bureaucrat const &bureaucrat) const;
};

#endif
