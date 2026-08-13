/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:39:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/28 10:07:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
  std::cout << "Int constructor called" << std::endl;
  this->fixedPointValue = num << this->fractionalBits;
}

Fixed::Fixed(const float num)
{
  std::cout << "Float constructor called" << std::endl;
  this->fixedPointValue = roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &src)
    this->fixedPointValue = src.getRawBits();
  return (*this);
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
  return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
  this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
  return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const
{
  return (this->fixedPointValue >> this->fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
  out << src.toFloat();
  return (out);
}
