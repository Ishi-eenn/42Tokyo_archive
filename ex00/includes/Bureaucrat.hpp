#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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
    Bureaucrat(const Bureaucrat &b);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &b);

    const std::string &getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();

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
