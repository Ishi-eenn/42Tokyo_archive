#ifndef INTERN_FORM_HPP
#define INTERN_FORM_HPP

#include <string>

class AForm;

class Intern {
  public:
    Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    ~Intern();

    AForm *makeForm(const std::string &form_name, const std::string &target) const;
};

#endif
