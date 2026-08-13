/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:45:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 15:05:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string name;

	public:
		Zombie(const std::string &name);
		~Zombie();
		void announce();
};

Zombie *newZombie(std::string);

void randomChump(std::string);

#endif
