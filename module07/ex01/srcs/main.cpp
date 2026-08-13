#include "iter.hpp"

template <typename T>
void printData(T value) {
  std::cout << value << " ";
}

void printInt(int value) {
  std::cout << value << " ";
}

void printStr(const std::string &str) {
  std::cout << str << " ";
}

int main(void) {
  int arrayInt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::string arrayStr[3] = {"apple", "banana", "cherry"};
  const char *kArrayStr[3] = {"apple", "banana", "cherry"};

  std::cout << "arrayInt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};" << std::endl;
  iter<int, void(*)(int)>(arrayInt, 10, printInt);
  std::cout << std::endl << std::endl;

  std::cout << "arrayStr[3] = {\"apple\", \"banana\", \"cherry\"};" << std::endl;
  iter<std::string, void(*)(const std::string &)>(arrayStr, 3, printStr);
  std::cout << std::endl << std::endl;

  std::cout << "kArrayStr[3] = {\"apple\", \"banana\", \"cherry\"};" << std::endl;
  iter<const char *, void(*)(const char *)>(kArrayStr, 3, printData<const char *>);
  std::cout << std::endl << std::endl;

  iter(arrayInt, 5, printData<int>);
  std::cout << std::endl;

  iter(arrayStr, 3, printData<std::string>);
  std::cout << std::endl;

  iter(kArrayStr, 2, printData<const char *>);
  std::cout << std::endl;

  return 0;
}
