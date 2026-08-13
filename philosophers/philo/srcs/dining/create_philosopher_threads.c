/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher_threads.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:11:11 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 09:54:20 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

static bool	create_philosopher_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&data->threads[i],
				NULL,
				&routine,
				&data->philos[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	create_philosopher_threads_and_check(t_data *data)
{
	if (!create_philosopher_threads(data))
	{
		print_error(ERR_PTHRED);
		return (false);
	}
	return (true);
}
