/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:03:38 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static bool	is_numeric(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

bool	is_all_argcument_numeric(const int argc, const char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
		{
			print_error(ERR_AC_NUMERIC);
			return (false);
		}
		i++;
	}
	return (true);
}
