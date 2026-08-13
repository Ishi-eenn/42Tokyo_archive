/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_below_threshold.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:05:18 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static bool	is_below_threshold(char *str, int threshold)
{
	if (ft_atoi(str) < threshold)
	{
		print_error(ERR_AC_SMALL);
		return (false);
	}
	return (true);
}

bool	is_all_argcument_thresholds(int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < 5)
	{
		if (is_below_threshold(argv[i], 1) == false)
			return (false);
		i++;
	}
	if (argc == 6)
		if (is_below_threshold(argv[i], 0) == false)
			return (false);
	return (true);
}
