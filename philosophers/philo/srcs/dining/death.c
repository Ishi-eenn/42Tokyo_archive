/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:10:12 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 11:14:49 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

static u_int64_t	get_time_last_eaten(t_philo *philo)
{
	u_int64_t	time_last_eaten;

	pthread_mutex_lock(&philo->mtx_time_last_eaten);
	time_last_eaten = philo->time_last_eaten;
	pthread_mutex_unlock(&philo->mtx_time_last_eaten);
	return (time_last_eaten);
}

void	*monitor_death(void *arg)
{
	t_data	*data;
	int		i;

	data = arg;
	while (!is_exit(data))
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			if (get_time(get_time_last_eaten(&data->philos[i]))
				> (u_int64_t)data->time_to_die)
			{
				print_state(&data->philos[i], "died");
				set_exit(data);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
