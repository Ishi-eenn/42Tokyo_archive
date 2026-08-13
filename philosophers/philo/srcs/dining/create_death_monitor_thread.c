/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_death_monitor_thread.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:01:47 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 09:54:17 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

static bool	create_death_monitor_thread(t_data *data)
{
	if (pthread_create(&data->monitor_death, NULL, &monitor_death, data))
		return (false);
	return (true);
}

bool	create_death_monitor_thread_and_check(t_data *data)
{
	if (!create_death_monitor_thread(data))
	{
		print_error(ERR_PTHRED);
		return (false);
	}
	return (true);
}
