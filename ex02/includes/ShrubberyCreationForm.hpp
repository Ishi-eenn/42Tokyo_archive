#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
  private:
    static const std::string kFormName;
    static const unsigned int kGradeForSign = 145;
    static const unsigned int kGradeForExecute = 137;
    static const std::string  kFileSuffix;
    std::string target_;

    ShrubberyCreationForm();
    void executeEachForm(Bureaucrat const &bureaucrat) const;
    void WriteTreeToFile() const;

  public:
    explicit ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &s);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s);
    ~ShrubberyCreationForm();

    const std::string &getTarget() const;
    void execute(Bureaucrat const &bureaucrat) const;
};

#endif
