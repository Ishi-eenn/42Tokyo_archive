/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_eaten_times.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:00:02 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:30 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_last_eaten_times(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i].time_last_eaten = data->time_start;
		i++;
	}
}
