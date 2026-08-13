/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:43:33 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 09:54:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"

bool	dining(t_data *data)
{
	if (!create_philosopher_threads_and_check(data))
		return (false);
	if (!create_death_monitor_thread_and_check(data))
		return (false);
	if (!create_eat_limit_monitor_thread_and_check(data))
		return (false);
	return (true);
}
