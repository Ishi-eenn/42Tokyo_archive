#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <new>

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
  (void)intern;
}

Intern &Intern::operator=(const Intern &intern) {
  (void)intern;

  return *this;
}

Intern::~Intern() {}

static AForm *CreatePresidentialPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

static AForm *CreateRobotomyRequestForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

static AForm *CreateShrubberyCreationForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

typedef AForm *(*CreateFormFunc)(const std::string &);
typedef std::pair<const std::string, CreateFormFunc> FormPair;

static CreateFormFunc GetCreateFormFunction(const std::string &form_name) {
  static const FormPair forms[] = {
    std::make_pair("presidential pardon", &CreatePresidentialPardonForm),
    std::make_pair("robotomy request", &CreateRobotomyRequestForm),
    std::make_pair("shrubbery creation", &CreateShrubberyCreationForm)
  };

  const size_t size = sizeof(forms) / sizeof(forms[0]);

  for (size_t i = 0; i < size; i++)
    if (forms[i].first == form_name)
      return forms[i].second;

  return NULL;
}

static AForm *TryMakeForm(const std::string &form_name, const std::string &target) {
  CreateFormFunc create_form = GetCreateFormFunction(form_name);

  if (create_form == NULL)
    throw std::logic_error("Error: invalid Form name");

  return create_form(target);
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target) const {
  try {
    AForm *form = TryMakeForm(form_name, target);
    std::cout <<  "Intern creates " << form_name << std::endl;
    return form;
  } catch (const std::exception &e) {
    std::cerr << "Intern creates Form failed. => " << e.what() << std::endl;
    return NULL;
  }
}
