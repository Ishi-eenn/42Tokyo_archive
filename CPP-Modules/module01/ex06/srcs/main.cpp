/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:22:47 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/13 11:40:23 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;

	if(argc != 2){
		std::cerr << "Error: Invalid arguments." << std::endl;
		return (1);
	}

	harl.complain(argv[1]);
	return (0);
}

