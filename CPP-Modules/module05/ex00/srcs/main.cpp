#include "Bureaucrat.hpp"

void draw_line(int n) {
  int len = 10;
  for(int i = 0; i < len; i++) {
    if(i == len / 2)
      std::cout << " " << n << " ";
    std::cout << "-";
  }
  std::cout << std::endl;
}

int main() {
  int i = 1;

  try {
    draw_line(i++);
    Bureaucrat human("yamada", 10);
    std::cout << human;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    draw_line(i++);
    Bureaucrat  human("yamada", -10);
    std::cout << human;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    draw_line(i++);
    Bureaucrat human("yamada", 151);
    std::cout << human;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    draw_line(i++);
    Bureaucrat  human("yamada", 1);
    std::cout << human;
    human.incrementGrade();
    std::cout << human;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    draw_line(i++);
    Bureaucrat  human("yamada", 150);
    std::cout << human;
    human.decrementGrade();
    std::cout << human;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return (0);
}
