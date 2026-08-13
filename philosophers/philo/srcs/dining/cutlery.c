/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutlery.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:28:56 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 10:31:20 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->mtx_fork_l);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->mtx_fork_r);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->mtx_fork_r);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->mtx_fork_l);
		print_state(philo, "has taken a fork");
	}
}

void	put_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->mtx_fork_l);
		pthread_mutex_unlock(philo->mtx_fork_r);
	}
	else
	{
		pthread_mutex_unlock(philo->mtx_fork_r);
		pthread_mutex_unlock(philo->mtx_fork_l);
	}
}
