/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:15:57 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:34 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].mtx_fork_l = &data->mtx_forks[i];
		data->philos[i].mtx_fork_r
			= &data->mtx_forks[(i + 1) % data->num_of_philo];
		if (pthread_mutex_init(&data->philos[i].mtx_eat_count, NULL))
			return (false);
		if (pthread_mutex_init(&data->philos[i].mtx_time_last_eaten, NULL))
			return (false);
		data->philos[i].data = data;
		i++;
	}
	return (true);
}

bool	init_philo_and_check(t_data *data)
{
	if (!init_philo(data))
	{
		print_error(ERR_MTX_INIT);
		return (false);
	}
	return (true);
}
