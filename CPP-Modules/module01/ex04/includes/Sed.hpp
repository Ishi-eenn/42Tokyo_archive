/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:42:29 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 23:37:20 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Sed
{
	private:
		std::string fileName;
		std::string content;

	private:
		void setContent(std::string &content);
		std::string getContent();
		void readContentFromFile();
		void replaceStringInFile(std::string s1, std::string s2);

	public:
		Sed(const std::string &fileName);
		void replace(std::string s1, std::string s2);
};

#endif
