/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:40:18 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/12 16:55:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{
	private:
		std::string type;

	public:
		Weapon(const std::string &type);
		const std::string &getType() const;
		void setType(const std::string &type);
};

#endif
