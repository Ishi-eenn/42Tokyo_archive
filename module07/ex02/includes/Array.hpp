#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array {
  public:
    Array();
    Array(const unsigned int n);
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);
    const T &operator[](const std::size_t index) const;
    T &operator[](const std::size_t index);
    unsigned int size() const;

  private:
    T *array_;
    unsigned int size_;
    T   *dupArray(const Array &other);
    void throwIndexOutOfRange(const std::size_t index) const;
};

#include "Array.tpp"

#endif
