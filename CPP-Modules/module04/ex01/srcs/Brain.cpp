/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:57:52 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/04 00:47:19 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
  std::cerr << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
  std::cerr << "Brain copy constructor called" << std::endl;
  *this = copy;
}

Brain::~Brain()
{
  std::cerr << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
  std::cerr << "Brain assignation operator called" << std::endl;
  if (this != &copy) {
    for (int i = 0; i < ideasCount; i++)
      ideas[i] = copy.ideas[i];
  }
  return *this;
}

void Brain::setIdea(int index, std::string idea) {
  ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
  return ideas[index];
}
