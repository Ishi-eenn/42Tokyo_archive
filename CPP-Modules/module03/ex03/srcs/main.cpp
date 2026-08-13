/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:39:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/03 03:58:44 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 1  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    DiamondTrap tsishika("tsishika");

    tsishika.attack("nop");
    tsishika.ClapTrap::attack("nop");
    tsishika.ScavTrap::attack("nop");
    tsishika.takeDamage(20);
    tsishika.beRepaired(10);
    tsishika.whoAmI();
  }
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 2  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    DiamondTrap tsishika("tsishika");

    for (int i = 0; i < 51; i++) {
      tsishika.attack("nop");
    }
  }
}
