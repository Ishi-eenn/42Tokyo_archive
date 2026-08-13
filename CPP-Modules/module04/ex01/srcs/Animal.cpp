/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:48 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 00:08:56 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
  std::cerr << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
  std::cerr << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
  std::cerr << "Animal copy constructor called" << std::endl;
  *this = copy;
}

Animal::~Animal()
{
  std::cerr << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
  std::cerr << "Animal assignation operator called" << std::endl;
  if (this != &copy)
    this->type = copy.type;
  return *this;
}

void Animal::makeSound() const {
  std::cout << "Animal sound" << std::endl;
}

const std::string &Animal::getType() const {
  return type;
}
