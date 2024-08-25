#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private:
    const std::string name_;
    bool is_signed_;
    const unsigned int grade_for_sign_;
    const unsigned int grade_for_execute_;

    void ThrowGradeException(const unsigned int grade) const;
    void GradeTooHighException() const;
    void GradeTooLowException() const;
    virtual void executeEachForm(Bureaucrat const &bureaucrat) const = 0;

  protected:
    AForm();

  public:
    AForm(const std::string &name, const unsigned int grade_for_sign, const unsigned int grade_for_execute);
    AForm(const AForm &form);
    virtual ~AForm();
    AForm &operator=(const AForm &form);

    class NotSignedException : public std::logic_error {
      public:
        NotSignedException();
    };

    const std::string &getName() const;
    bool getIsSigned() const;
    unsigned int getGradeForSign() const;
    unsigned int getGradeForExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
