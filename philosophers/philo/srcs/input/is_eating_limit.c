/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:12:21 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:48 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

bool	is_eating_limit_zero(int argc, char **argv)
{
	if (argc == 6)
		return (ft_atoi(argv[5]) == 0);
	return (false);
}
