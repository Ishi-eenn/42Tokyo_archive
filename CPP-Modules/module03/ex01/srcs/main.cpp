/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:39:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/30 23:41:43 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 1  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    ScavTrap tsishika("tsishika");
    ScavTrap nop("nop");

    for (int i = 0; i < 6; i++) {
      nop.attack("tsishika");
      tsishika.takeDamage(20);
    }
    tsishika.beRepaired(10);
    tsishika.guardGate();
    nop.guardGate();
  }
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 2  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    ScavTrap tsishika("tsishika");

    for (int i = 0; i < 51; i++) {
      tsishika.beRepaired(10);
    }
    tsishika.attack("nop");
  }
}
