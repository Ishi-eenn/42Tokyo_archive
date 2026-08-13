#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
struct Data;

class Serializer {
  private:
    Serializer();
    Serializer(const Serializer &s);
    ~Serializer();
    Serializer &operator=(const Serializer &s);

  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
