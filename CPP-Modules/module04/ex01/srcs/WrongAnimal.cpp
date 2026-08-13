/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:54 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/01 01:42:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
  std::cerr << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
  std::cerr << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
  std::cerr << "WrongAnimal copy constructor called" << std::endl;
  *this = copy;
}

WrongAnimal::~WrongAnimal()
{
  std::cerr << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
  std::cerr << "WrongAnimal assignation operator called" << std::endl;
  if (this != &copy)
    this->type = copy.type;
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound" << std::endl;
}

const std::string &WrongAnimal::getType() const {
  return type;
}
