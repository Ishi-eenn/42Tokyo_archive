/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:39:27 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/11 12:30:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void displayAvailableCommandsTitle(){
	std::cout << "The available commands are EXIT, ADD and SEARCH." << std::endl;
}

void displayErrorAndExit(std::string string, bool isNewlineNeeded){
	if(isNewlineNeeded)
		std::cout << std::endl;
	std::cerr << string << std::endl;
	exit(1);
}

void displayAndExit(std::string string){
	std::cout << string << std::endl;
	exit(0);
}
