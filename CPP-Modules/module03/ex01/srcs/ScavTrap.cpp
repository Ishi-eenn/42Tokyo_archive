/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:14:21 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/02 16:50:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cerr << "ScavTrap default constructor called" << std::endl;
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  maxHitPoints = 100;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cerr << "ScavTrap name constructor called" << std::endl;
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  maxHitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
  std::cerr << "ScavTrap copy constructor called" << std::endl;
  *this = copy;
}

ScavTrap::~ScavTrap() {
  std::cerr << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
  std::cerr << "ScavTrap assignation operator called" << std::endl;
  if (this != &copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
  }
  return *this;
}

void ScavTrap::attack(std::string const &target) {
  if (energyPoints == 0) {
    std::cout << "ScavTrap " << name << " cannot attack because it has no energy points." << std::endl;
  } else if (hitPoints == 0) {
    std::cout << "ScavTrap " << name << " cannot attack because it is already dead." << std::endl;
  } else {
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " has entered in Gate keeper mode." << std::endl;
}
