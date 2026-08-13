/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_eat_limit_monitor_thread.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:16:23 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 19:15:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

static bool	create_eat_limit_monitor_thread(t_data *data)
{
	if (data->eat_limit > 0 && data->num_of_philo > 1)
	{
		if (pthread_create(&data->monitor_eat_limit,
				NULL, &monitor_eat_count_limit, data))
			return (false);
	}
	return (true);
}

bool	create_eat_limit_monitor_thread_and_check(t_data *data)
{
	if (!create_eat_limit_monitor_thread(data))
	{
		print_error(ERR_PTHRED);
		return (false);
	}
	return (true);
}
