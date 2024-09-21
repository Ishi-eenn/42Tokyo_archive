#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

void test(const Data *data1, const Data *data2) {
  std::cout << data1 << " " << data2 << std::endl;

  if (data1 == data2 && data1->index == data2->index)
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}

int main() {
  Data data = {42};

  Data *before = &data;

  try {
    std::uintptr_t tmp = Serializer::serialize(before);
    Data *after = Serializer::deserialize(tmp);
    test(before, after);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Serializer::serialize(NULL);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
