#include <iostream>

#include "whatever.hpp"

int main(void) {
  {
    std::cout << "Subject tests" << std::endl;
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Additional tests(int)" << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Additional tests(string)" << std::endl;
    std::string a = "chaine1";
    std::string b = "chaine2";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Additional tests(float)" << std::endl;
    float a = 42.42f;
    float b = 21.21f;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Additional tests(double)" << std::endl;
    double a = 42.42;
    double b = 21.21;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Additional tests(char)" << std::endl;
    char a = 'a';
    char b = 'b';
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
  }
  {
    std::cout << "Additional tests(bool)" << std::endl;
    bool a = true;
    bool b = false;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
