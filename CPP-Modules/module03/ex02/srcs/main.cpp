/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:39:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/01 00:29:55 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
  {
    std::cout << "/**********\\" << std::endl;
    std::cout << "*  case 1  *" << std::endl;
    std::cout << "\\**********/" << std::endl;

    FragTrap tsishika("tsishika");

    tsishika.attack("nop");
    tsishika.takeDamage(20);
    tsishika.beRepaired(10);
    tsishika.highFivesGuys();
  }
}
