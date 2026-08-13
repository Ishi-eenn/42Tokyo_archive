#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::const_iterator easyfind(T const &container, int value);

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif
