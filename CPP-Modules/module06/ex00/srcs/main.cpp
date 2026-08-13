#include "ScalarConverter.hpp"
#include <iostream>

void printUsage() {
  std::cerr << "Usage: ./ex00 or ./ex00 [string]" << std::endl;
}

void testcase(const std::string &str) {
  std::cout << "testcase: " << str << std::endl;
  ScalarConverter::convert(str);
  std::cout << std::endl;
}

void subjectTests() {
  std::cout << "subject test cases..." << std::endl << std::endl;
  testcase("0");
  testcase("nan");
  testcase("42.0f");
}

int main(int argc, char** argv) {
  if (argc == 1)
    subjectTests();
  else if (argc == 2)
    ScalarConverter::convert(argv[1]);
  else {
    printUsage();
    return 1;
  }
  return 0;
}
