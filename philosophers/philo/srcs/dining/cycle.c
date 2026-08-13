/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:49:42 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 19:13:43 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

bool	eating_cycle(t_philo *philo)
{
	take_forks(philo);
	print_state(philo, "is eating");
	set_time_last_eaten(philo);
	if (is_exit(philo->data))
	{
		put_forks(philo);
		return (false);
	}
	ft_wait(philo->data->time_to_eat);
	put_forks(philo);
	return (true);
}

bool	sleeping_cycle(t_philo *philo)
{
	print_state(philo, "is sleeping");
	increment_eat_count(philo);
	if (is_exit(philo->data))
		return (false);
	ft_wait(philo->data->time_to_sleep);
	return (true);
}

void	thinking_cycle(t_philo *philo)
{
	print_state(philo, "is thinking");
	if ((philo->data->num_of_philo % 2) && !is_exit(philo->data))
		ft_wait(philo->data->time_to_eat * 2 - philo->data->time_to_sleep);
}
