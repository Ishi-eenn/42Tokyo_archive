/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:16:00 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 09:18:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	init_table(t_data *data)
{
	if (!init_data_structures_and_check(data))
		return (false);
	if (!init_mutex_and_check(data))
		return (false);
	if (!init_philo_and_check(data))
		return (false);
	data->time_start = get_time(0);
	init_last_eaten_times(data);
	return (true);
}

static void	pthread_join_for_philosophers_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
}

static void	release_used_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->mtx_forks[i]);
		pthread_mutex_destroy(&data->philos[i].mtx_eat_count);
		pthread_mutex_destroy(&data->philos[i].mtx_time_last_eaten);
		i++;
	}
	pthread_mutex_destroy(&data->mtx_exit);
	pthread_mutex_destroy(&data->mtx_printf);
}

void	delete_table(t_data *data)
{
	if (data->eat_limit > 0 && data->num_of_philo > 1)
		pthread_join(data->monitor_eat_limit, NULL);
	pthread_join_for_philosophers_threads(data);
	pthread_join(data->monitor_death, NULL);
	release_used_mutexes(data);
	free(data->threads);
	free(data->mtx_forks);
	free(data->philos);
}
