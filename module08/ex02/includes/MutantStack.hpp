#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

  MutantStack();
  ~MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);

  iterator begin();
  iterator end();

  reverse_iterator rbegin();
  reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif
