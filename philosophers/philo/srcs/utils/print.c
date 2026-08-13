/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:30:38 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 11:14:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
}

void	print_state(t_philo *philo, const char *state)
{
	u_int64_t	timestamp;

	pthread_mutex_lock(&philo->data->mtx_printf);
	if (!is_exit(philo->data))
	{
		timestamp = get_time(philo->data->time_start);
		printf("%llu %d %s\n", timestamp, philo->id, state);
	}
	pthread_mutex_unlock(&philo->data->mtx_printf);
}
