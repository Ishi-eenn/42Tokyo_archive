/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:39:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/28 10:11:18 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
  std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
  std::cerr << "Int constructor called" << std::endl;
  this->fixedPointValue = num << this->fractionalBits;
}

Fixed::Fixed(const float num)
{
  std::cerr << "Float constructor called" << std::endl;
  this->fixedPointValue = roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
  std::cerr << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
  std::cerr << "Copy assignment operator called" << std::endl;
  if (this != &src)
    this->fixedPointValue = src.getRawBits();
  return (*this);
}

Fixed::~Fixed()
{
  std::cerr << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed &src) const
{
  return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const
{
  return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const
{
  return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const
{
  return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const
{
  return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const
{
  return (this->getRawBits() != src.getRawBits());
}

Fixed Fixed::operator+(const Fixed &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed &Fixed::operator++(void)
{
  setRawBits(this->getRawBits() + 1);
  return (*this);
}

Fixed Fixed::operator++(int)
{
  Fixed tmp = *this;
  setRawBits(this->getRawBits() + 1);
  return (tmp);
}

Fixed &Fixed::operator--(void)
{
  setRawBits(this->getRawBits() - 1);
  return (*this);
}

Fixed Fixed::operator--(int)
{
  Fixed tmp = *this;
  setRawBits(this->getRawBits() - 1);
  return (tmp);
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
  if (left.getRawBits() < right.getRawBits())
    return (left);
  return (right);
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
  if (left.getRawBits() < right.getRawBits())
    return (left);
  return (right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
  if (left.getRawBits() > right.getRawBits())
    return (left);
  return (right);
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
  if (left.getRawBits() > right.getRawBits())
    return (left);
  return (right);
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
