/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:29 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/04 00:10:10 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
  public:
    Dog();
    Dog(const Dog &copy);
    Dog &operator=(const Dog &copy);
    virtual ~Dog();

    virtual void makeSound() const;
};

#endif
