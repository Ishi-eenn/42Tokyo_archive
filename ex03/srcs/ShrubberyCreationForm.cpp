#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::kFormName   = "Shrubbery Creation";
const std::string ShrubberyCreationForm::kFileSuffix = "_shrubbery";

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(kFormName, kGradeForSign, kGradeForExecute), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s.getName(), s.getGradeForSign(), s.getGradeForExecute()), target_(s.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s) {
  if (this != &s) {
    AForm::operator=(s);
    target_ = s.getTarget();
  }

  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const {
  return target_;
}

void ShrubberyCreationForm::writeTreeToFile() const {
  const std::string filename = getTarget() + kFileSuffix;
  std::ofstream out_file(filename.c_str(), std::ios_base::out);

  if (out_file.is_open()) {
    out_file << "     *\n"
                "    ***\n"
                "   *****\n"
                "  *******\n"
                " *********\n"
                "     |\n"
                "     |\n";

  } else {
    throw std::runtime_error("Error: open failed");
  }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);
}

void ShrubberyCreationForm::executeEachForm(Bureaucrat const &executor) const {
  std::cout << executor.getName() << ": " << getTarget();
  try {
    writeTreeToFile();
    std::cout <<  " => Success"  << std::endl;
  } catch (const std::exception &e) {
    std::cout <<  " => Fail"  << std::endl;
    throw;
  }
}
