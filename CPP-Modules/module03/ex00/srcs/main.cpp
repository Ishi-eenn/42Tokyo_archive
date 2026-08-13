/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:39:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/02 16:47:02 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 1  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    ClapTrap clap("tsishika");

    clap.attack("nop");
    clap.takeDamage(5);
    clap.beRepaired(5);
    clap.takeDamage(10);
    clap.attack("Anthony");
    clap.takeDamage(10);
    clap.beRepaired(10);
  }
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 2  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    ClapTrap clap("tsishika");

    for (int i = 0; i < 11; i++)
      clap.attack("nop");
    clap.beRepaired(10);
    clap.takeDamage(1000);
  }
}
