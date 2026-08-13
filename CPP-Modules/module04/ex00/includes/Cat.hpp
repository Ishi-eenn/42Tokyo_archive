/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:25 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/04 00:10:06 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat &copy);
    Cat &operator=(const Cat &copy);
    virtual ~Cat();

    virtual void makeSound() const;
};

#endif
