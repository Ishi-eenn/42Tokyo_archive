#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <iostream>

Base* generate(void) {
  const int num = std::rand() % 3;
  Base* base = NULL;

  try {
    if (num == 0) {
      base = new A();
      std::cout << "Generate type : A" << std::endl;
    } else if (num == 1) {
      base = new B();
      std::cout << "Generate type : B" << std::endl;
    } else {
      base = new C();
      std::cout << "Generate type : C" << std::endl;
    }
  } catch (const std::bad_alloc& e) {
    throw std::invalid_argument(e.what());
  }

  return base;
}

void identify(Base *p) {
  if (p == NULL) {
    throw std::invalid_argument("argument is NULL");
  }
  if (dynamic_cast<A *>(p))
    std::cout << "This is a A class pointer" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "This is a B class pointer" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "This is a C class pointer" << std::endl;
  else
    throw std::invalid_argument("invalid argument");
}

void identify(Base &p) {
  try {
    A a_ref = dynamic_cast<A &>(p);
    std::cout << "This is a A class reference" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }

  try {
    B b_ref = dynamic_cast<B &>(p);
    std::cout << "This is a B class reference" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }

  try {
    C c_ref = dynamic_cast<C &>(p);
    std::cout << "This is a C class reference" << std::endl;
    return;
  } catch (std::bad_cast &e) {
  }

  throw std::invalid_argument("invalid argument");
}

int main() {
  std::srand(std::time(0));

  {
    std::cout << "Test 1" << std::endl;
    try {
      Base *p = generate();
      identify(p);
      identify(*p);
      delete p;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  try {
    std::cout << "Test 2" << std::endl;
    identify(NULL);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
