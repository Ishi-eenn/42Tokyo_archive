/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:34:16 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 23:40:26 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv){
	Sed *sed;

	if(argc != 4){
		std::cerr << "Invalid number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <search string> <replace string>" << std::endl;
		return (1);
	}

	sed = new Sed(argv[1]);
	sed->replace(argv[2], argv[3]);
	delete sed;
	return (0);
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q replace");
// }
