/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:36:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/03/31 12:16:01 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  fixedPointValue = src.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
  std::cout << "setRawBits member function called" << std::endl;
  fixedPointValue = raw;
}
