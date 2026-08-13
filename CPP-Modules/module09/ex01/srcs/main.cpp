#include "RPN.hpp"
#include <iostream>

bool isSpace(const char c) {
  return c == ' ';
}

void hasSpaceBetweenEachChar(const std::string& str) {
  for (size_t i = 1; i < str.length(); i += 2)
    if (!isSpace(str[i]))
      throw std::invalid_argument("Invalid expression.");
}

int main(int argc, char **argv) {
  if(argc != 2)
    std::cerr << "Usage: ./RPN [string]" << std::endl;
  else {
    try {
      hasSpaceBetweenEachChar(argv[1]);
      std::cout << RPN::reversePolishNotation(argv[1]) << std::endl;
    } catch (std::exception &e) {
      #ifdef DEBUG
        std::cerr << "Error: " << e.what() << std::endl;
      #else
        std::cerr << "Error" << std::endl;
      #endif
    }
  }
  return 0;
}
