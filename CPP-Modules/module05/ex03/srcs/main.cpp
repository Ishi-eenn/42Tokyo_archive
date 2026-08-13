#include <unistd.h>
#include <sys/ioctl.h>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

static size_t get_term_line() {
  winsize	terminal_size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
  return (terminal_size.ws_col);
}

static void draw_terminal_line() {
  size_t	terminal_col;

  terminal_col = get_term_line();
  for (size_t i = 0; i < terminal_col; i++)
    std::cout << "=";
  std::cout << std::endl;
  return ;
}

int main(void) {
  draw_terminal_line();
  {
    Bureaucrat  human("42student", 1);
    Intern      slave;
    AForm        *tmp;

    tmp = slave.makeForm("presidential pardon", "yamada");
    human.signForm(*tmp);
    human.executeForm(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  {
    Bureaucrat  human("42student", 1);
    Intern      slave;
    AForm        *tmp;

    tmp = slave.makeForm("robotomy request", "yamada");
    human.signForm(*tmp);
    human.executeForm(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  {
    Bureaucrat  human("42student", 1);
    Intern      slave;
    AForm        *tmp;

    tmp = slave.makeForm("shrubbery creation", "yamada");
    human.signForm(*tmp);
    human.executeForm(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  {
    Intern  slave;
    AForm    *tmp;

    tmp = slave.makeForm("nothing", "yamada");
    delete tmp;
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
