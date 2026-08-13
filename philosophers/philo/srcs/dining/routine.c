/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:55:02 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 19:13:29 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

static void	*single_philosopher_action(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_fork_l);
	print_state(philo, "has taken a fork");
	while (!is_exit(philo->data))
		usleep(1000);
	pthread_mutex_unlock(philo->mtx_fork_l);
	return (NULL);
}

static void	delay_for_odd_id(int id)
{
	if (id % 2)
		usleep(1000);
}

static bool	should_continue_dining(t_philo *philo)
{
	if (!is_exit(philo->data))
	{
		if (philo->data->eat_limit < 0)
			return (true);
		if (get_eat_count(philo) < philo->data->eat_limit)
			return (true);
	}
	return (false);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->num_of_philo == 1)
		return (single_philosopher_action(philo));
	delay_for_odd_id(philo->id);
	while (should_continue_dining(philo))
	{
		if (!eating_cycle(philo))
			return (NULL);
		if (!sleeping_cycle(philo))
			return (NULL);
		thinking_cycle(philo);
	}
	return (NULL);
}
