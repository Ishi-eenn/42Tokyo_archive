/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:35:58 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/27 14:26:32 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
    int fixedPointValue;
    static const int fractionalBits = 8;

  public:
    Fixed();
    Fixed(const Fixed &src);
    ~Fixed();
    Fixed &operator=(const Fixed &src);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
