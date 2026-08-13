/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:57:36 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:44 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

bool	is_argument_count(const int argc)
{
	if (argc < 5 || 6 < argc)
	{
		print_error(ERR_AC_NUMBER);
		return (false);
	}
	return (true);
}
