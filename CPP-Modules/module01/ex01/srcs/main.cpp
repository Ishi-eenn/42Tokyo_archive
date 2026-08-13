/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:49:11 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 15:15:08 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int n = 10;
	Zombie *zombies = zombieHorde(n, "Alice");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
