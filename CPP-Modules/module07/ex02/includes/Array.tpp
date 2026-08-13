#include <iostream>

template <typename T>
Array<T>::Array() : size_(0) {
  try {
    array_ = new T[0]();
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Error: Memory allocation failed");
  }
}

template <typename T>
Array<T>::Array(const unsigned int n) : size_(n) {
  try {
    array_ = new T[n]();
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Error: Memory allocation failed");
  }
}

template <typename T>
Array<T>::Array(const Array &other) : size_(other.size_) {
  try {
    array_ = dupArray(other);
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Error: Memory allocation failed");
  }
}

template <typename T>
Array<T>::~Array() {
  delete[] array_;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    T *tmp = DupArray(other);
    delete[] array_;
    array_ = tmp;
    size_  = other.size_;
  }
  return *this;
}

template <typename T>
const T &Array<T>::operator[](const std::size_t index) const {
  throwIndexOutOfRange(index);
  return array_[index];
}

template <typename T>
T &Array<T>::operator[](const std::size_t index) {
  throwIndexOutOfRange(index);
  return array_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}

template <typename T>
T *Array<T>::dupArray(const Array &other) {
  T *tmp = NULL;
  try {
    tmp = new T[other.size_]();
    for (unsigned int i = 0; i < other.size_; i++)
      tmp[i] = other.array_[i];
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Error: Memory allocation failed");
  }
  return tmp;
}

template <typename T>
void Array<T>::throwIndexOutOfRange(const std::size_t index) const {
  if (index >= size_)
    throw std::out_of_range("Error: out of bounds index");
}
