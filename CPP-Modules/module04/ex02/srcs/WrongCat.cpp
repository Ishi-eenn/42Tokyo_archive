/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:56 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 00:09:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
  std::cerr << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
  std::cerr << "WrongCat copy constructor called" << std::endl;
  *this = copy;
}

WrongCat::~WrongCat()
{
  std::cerr << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
  std::cerr << "WrongCat assignation operator called" << std::endl;
  if (this != &copy)
    this->type = copy.type;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "Meow Meow Meow Meow Meow Meow Meow Meow Meow Meow" << std::endl;
}
