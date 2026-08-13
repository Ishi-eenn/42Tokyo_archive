/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:50:22 by tsishika          #+#    #+#             */
/*   Updated: 2024/02/11 12:29:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>

void displayAvailableCommandsTitle();
void displayErrorAndExit(std::string string, bool isNewlineNeeded);
void displayAndExit(std::string string);

#endif
