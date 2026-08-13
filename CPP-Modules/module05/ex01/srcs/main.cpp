#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <unistd.h>
#include <sys/ioctl.h>

void draw_line(int n) {
  int len = 10;
  for(int i = 0; i < len; i++) {
    if(i == len / 2)
      std::cout << " " << n << " ";
    std::cout << "-";
  }
  std::cout << std::endl;
}

int main(void) {
  int n = 1;
  try {
    draw_line(n++);
    Bureaucrat  human("yamada", 10);
    Form        licence("Access", 50, 10);

    std::cout << human;
    std::cout << licence;
    human.signForm(licence);
    std::cout << human;
    std::cout << licence;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    draw_line(n++);
    Bureaucrat  human("yamada", 140);
    Form        licence("Access", 50, 10);

    std::cout << human;
    std::cout << licence;
    human.signForm(licence);
    std::cout << human;
    std::cout << licence;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    draw_line(n++);
    Form  licence("error", -1, 30);

    std::cout << licence;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    draw_line(n++);
    Form  licence("error", 10, 0);

    std::cout << licence;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    draw_line(n++);
    Form  licence("error", 151, 30);

    std::cout << licence;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    draw_line(n++);
    Form  licence("error", 10, 151);

    std::cout << licence;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return (0);
}
