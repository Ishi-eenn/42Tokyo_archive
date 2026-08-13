/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:12:37 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	init_data_structures(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philos)
		return (false);
	data->threads = malloc(sizeof(pthread_t) * (data->num_of_philo));
	if (!data->threads)
	{
		free(data->philos);
		return (false);
	}
	data->mtx_forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->mtx_forks)
	{
		free(data->philos);
		free(data->threads);
		return (false);
	}
	data->exit = false;
	return (true);
}

bool	init_data_structures_and_check(t_data *data)
{
	if (!init_data_structures(data))
	{
		print_error(ERR_MALLOC);
		return (false);
	}
	return (true);
}
