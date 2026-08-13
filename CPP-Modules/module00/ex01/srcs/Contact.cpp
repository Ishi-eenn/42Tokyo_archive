/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:09:57 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/10 00:14:56 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string &firstName){
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName){
	this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname){
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber){
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret){
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}
