/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:42:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/13 17:59:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string &fileName): fileName(fileName)
{
	// do nothing
}

void Sed::setContent(std::string &content){
	this->content = content;
}

std::string Sed::getContent(){
	return (this->content);
}

void Sed::readContentFromFile(){
	std::string content;
	std::ifstream ifs(this->fileName);

	if (!ifs.is_open()){
		std::cerr << "Error: Failed to open" << std::endl;
		exit(1);
	}

	std::getline(ifs, content, '\0');
	ifs.close();
	this->setContent(content);
}

void Sed::replaceStringInFile(std::string s1, std::string s2){
	std::string content = this->getContent();
	std::ofstream ofs(this->fileName + ".replace");

	if (!ofs.is_open()) {
		std::cerr << "Error: Failed to open" << std::endl;
		exit(1);
	}

	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos){
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s1.length();
	}

	ofs << content;
	ofs.close();
}

void Sed::replace(std::string s1, std::string s2){
	this->readContentFromFile();
	this->replaceStringInFile(s1, s2);
}
