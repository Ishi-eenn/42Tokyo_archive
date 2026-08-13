/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:56:24 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/07 10:32:29 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define DEF_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static void print_uppercase_string(const char *str){
	if(str == NULL) return;
	for(int i = 0; str[i]; i++)
		std::cout << (char)std::toupper(str[i]);
}

int main(int argc, char **argv){
	if(argc == 1)
		return (std::cout << DEF_MESSAGE << std::endl, 0);
	for(int i = 1; i < argc; i++)
		print_uppercase_string(argv[i]);
	print_uppercase_string(NULL);
	std::cout << std::endl;
	return (0);
}
