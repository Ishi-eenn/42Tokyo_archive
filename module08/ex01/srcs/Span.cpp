#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &other)
{
  *this = other;
}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    _n = other._n;
    _v = other._v;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (_v.size() < _n)
    _v.push_back(n);
  else
    throw std::runtime_error("Span is full");
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  for (std::vector<int>::iterator it = begin; it != end; ++it)
    addNumber(*it);
}

int Span::shortestSpan() {
  if (_v.size() < 2)
    throw std::runtime_error("Span is too short");

  std::vector<int> v = _v;
  std::sort(v.begin(), v.end());
  int min = v[1] - v[0];
  for (unsigned int i = 2; i < v.size(); i++) {
    if (v[i] - v[i - 1] < min)
      min = v[i] - v[i - 1];
  }
  return min;
}

int Span::longestSpan() {
  if (_v.size() < 2)
    throw std::runtime_error("Span is too short");

  std::vector<int> v = _v;
  std::sort(v.begin(), v.end());
  return v[v.size() - 1] - v[0];
}


