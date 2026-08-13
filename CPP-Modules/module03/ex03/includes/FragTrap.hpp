/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:04:42 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 01:39:07 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
  public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &copy);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &copy);

    void attack(std::string const &target);
    void highFivesGuys(void);
};

#endif
