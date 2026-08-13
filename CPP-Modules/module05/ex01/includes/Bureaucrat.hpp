#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
  private:
    static const unsigned int kHighestGrade = 1;
    static const unsigned int kLowestGrade  = 150;
    const std::string name_;
    unsigned int grade_;

    Bureaucrat();
    void ThrowGradeException(const unsigned int grade) const;

  public:
    Bureaucrat(const std::string &name, const unsigned int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);

    const std::string &getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    static unsigned int getHighestGrade();
    static unsigned int getLowestGrade();
    void signForm(Form &form) const;

  class GradeTooHighException : public std::logic_error {
    public:
      GradeTooHighException();
  };

  class GradeTooLowException : public std::logic_error {
    public:
      GradeTooLowException();
  };
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &bureaucrat);

#endif
