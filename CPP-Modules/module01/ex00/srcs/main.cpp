/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:46:03 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 15:05:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie *zombie = newZombie("Bob");
	zombie->announce();
	delete zombie;

	randomChump("John");
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q zombie");
// }
