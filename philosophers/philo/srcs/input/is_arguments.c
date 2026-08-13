/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:59:14 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 10:20:05 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

bool	is_command_line_arguments(int argc, char **argv)
{
	if (!is_argument_count(argc))
		return (false);
	if (!is_all_argcument_numeric(argc, (const char **)argv))
		return (false);
	if (!is_integer_arguments(argc, argv))
		return (false);
	if (!is_all_argcument_thresholds(argc, argv))
		return (false);
	if (is_eating_limit_zero(argc, argv))
		return (false);
	return (true);
}
