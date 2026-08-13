/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:04:44 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/02 16:50:43 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cerr << "FragTrap Default constructor called" << std::endl;
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  maxHitPoints = 100;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cerr << "FragTrap name constructor called" << std::endl;
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  maxHitPoints = 100;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
  std::cerr << "FragTrap copy constructor called" << std::endl;
  *this = copy;
}

FragTrap::~FragTrap() {
  std::cerr << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
  std::cerr << "FragTrap assignation operator called" << std::endl;
  if (this != &copy) {
    this->name = copy.name;
    this->hitPoints = copy.hitPoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
  }
  return *this;
}

// void FragTrap::attack(std::string const &target) {
//   if (energyPoints == 0) {
//     std::cout << "FragTrap " << name << " cannot attack because it has no energy points." << std::endl;
//   } else if (hitPoints == 0) {
//     std::cout << "FragTrap " << name << " cannot attack because it is already dead." << std::endl;
//   } else {
//     energyPoints--;
//     std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
//   }
// }

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name << " requests a high five." << std::endl;
}
