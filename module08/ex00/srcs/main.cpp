#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void vector_check() {
  std::vector<int> v;
  for (int i = 1; i <= 10; i++)
    v.push_back(i);
  {
    std::vector<int>::iterator it = easyfind(v, 3);
    if (it != v.end())
      std::cout << *it << std::endl;
    else
      std::cout << "Not found" << std::endl;
  }
  {
    std::vector<int>::const_iterator it = easyfind(v, 42);
    if (it != v.end())
      std::cout << *it << std::endl;
    else
      std::cout << "Not found" << std::endl;
  }
}

void list_check() {
  std::list<int> l;
  for (int i = 1; i <= 10; i++)
    l.push_back(i);
  {
    std::list<int>::iterator it = easyfind(l, 3);
    if (it != l.end())
      std::cout << *it << std::endl;
    else
      std::cout << "Not found" << std::endl;
  }
  {
    std::list<int>::const_iterator it = easyfind(l, 42);
    if (it != l.end())
      std::cout << *it << std::endl;
    else
      std::cout << "Not found" << std::endl;
  }
}

int main() {
  vector_check();
  list_check();
  return 0;
}
