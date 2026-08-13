/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:19:18 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/28 10:14:07 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
  private:
    int fixedPointValue;
    static const int fractionalBits = 8;
  public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &src);
    ~Fixed();

    bool operator>(const Fixed &src) const;
    bool operator<(const Fixed &src) const;
    bool operator>=(const Fixed &src) const;
    bool operator<=(const Fixed &src) const;
    bool operator==(const Fixed &src) const;
    bool operator!=(const Fixed &src) const;

    Fixed operator+(const Fixed &src) const;
    Fixed operator-(const Fixed &src) const;
    Fixed operator*(const Fixed &src) const;
    Fixed operator/(const Fixed &src) const;

    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    static Fixed &min(Fixed &left, Fixed &right);
    static const Fixed &min(const Fixed &left, const Fixed &right);
    static Fixed &max(Fixed &left, Fixed &right);
    static const Fixed &max(const Fixed &left, const Fixed &right);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
