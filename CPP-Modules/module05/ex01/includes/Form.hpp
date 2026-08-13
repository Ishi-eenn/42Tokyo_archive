#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private:
    const std::string name_;
    bool is_signed_;
    const unsigned int grade_for_sign_;
    const unsigned int grade_for_execute_;

    Form();
    void ThrowGradeException(const unsigned int grade) const;
    void GradeTooHighException() const;
    void GradeTooLowException() const;

  public:
    Form(const std::string &name, const unsigned int grade_for_sign, const unsigned int grade_for_execute);
    Form(const Form &form);
    ~Form();
    Form &operator=(const Form &form);

    const std::string &getName() const;
    bool getIsSigned() const;
    unsigned int getGradeForSign() const;
    unsigned int getGradeForExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
