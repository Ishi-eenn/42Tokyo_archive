/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:09:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 16:19:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	const std::string strRaw = "HI THIS IS BRAIN";
	const std::string *strPtr = &strRaw;
	const std::string &strRef = strRaw;

	std::cout << "address:" << std::endl;
	std::cout << "strRaw: " << &strRaw << std::endl;
	std::cout << "strPtr: " << strPtr << std::endl;
	std::cout << "strRef: " << &strRef << std::endl;

	std::cout << "value:" << std::endl;
	std::cout << "strRaw: " << strRaw << std::endl;
	std::cout << "strPtr: " << *strPtr << std::endl;
	std::cout << "strRef: " << strRef << std::endl;
}


