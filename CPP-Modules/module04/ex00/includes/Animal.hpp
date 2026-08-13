/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:23 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/02 23:58:12 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
  protected:
    std::string type;

  public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &copy);
    virtual ~Animal();

    Animal &operator=(const Animal &copy);

    virtual void makeSound() const;
    const std::string &getType() const;
};

#endif
