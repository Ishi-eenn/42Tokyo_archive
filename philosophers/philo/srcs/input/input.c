/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:56:25 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 10:10:06 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

bool	input_data_from_cmd_line(t_data *data, int argc, char **argv)
{
	if (!is_command_line_arguments(argc, argv))
		return (false);
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_limit = -1;
	if (argc == 6)
		data->eat_limit = ft_atoi(argv[5]);
	return (true);
}
