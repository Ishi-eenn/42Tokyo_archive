/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:14:19 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/29 01:39:24 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &copy);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &copy);

    void attack(std::string const &target);
    void guardGate();
};

#endif
