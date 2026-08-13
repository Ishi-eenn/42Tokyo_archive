/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:40:28 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 19:16:24 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type){
	this->setType(type);
}

const std::string &Weapon::getType() const{
	return this->type;
}

void Weapon::setType(const std::string &type){
	this->type = type;
}
