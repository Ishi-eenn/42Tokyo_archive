/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:57:49 by tsishika          #+#    #+#             */
/*   Updated: 2024/05/04 00:46:49 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
  static const int ideasCount = 100;
    std::string ideas[ideasCount];

  public:
    Brain();
    Brain(const Brain &copy);
    ~Brain();

    Brain &operator=(const Brain &copy);

    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};

#endif
