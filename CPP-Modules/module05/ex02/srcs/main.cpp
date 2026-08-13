#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <unistd.h>
#include <sys/ioctl.h>

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
  try
  {
    Bureaucrat  human("yamada", 1);
    ShrubberyCreationForm bery("Gold");
    RobotomyRequestForm victim("42tokyo_student");
    PresidentialPardonForm  tmp("people");

    human.signForm(bery);
    human.signForm(victim);
    human.signForm(tmp);
    human.executeForm(bery);
    human.executeForm(victim);
    human.executeForm(tmp);
    human.executeForm(bery);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 150);
    ShrubberyCreationForm bery("Silver");
    RobotomyRequestForm victim("42tokyo_student");
    PresidentialPardonForm  tmp("people");

    human.signForm(bery);
    human.signForm(victim);
    human.signForm(tmp);
    human.executeForm(bery);
    human.executeForm(victim);
    human.executeForm(tmp);
    human.executeForm(bery);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 50);
    ShrubberyCreationForm bery("bronze");
    RobotomyRequestForm victim("42tokyo_student");
    PresidentialPardonForm  tmp("people");

    human.signForm(bery);
    human.signForm(victim);
    human.signForm(tmp);
    human.executeForm(bery);
    human.executeForm(victim);
    human.executeForm(tmp);
    human.executeForm(bery);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
