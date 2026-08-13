/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:44:15 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 14:12:55 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_exit(t_data *data)
{
	bool	exit_status;

	pthread_mutex_lock(&data->mtx_exit);
	exit_status = data->exit;
	pthread_mutex_unlock(&data->mtx_exit);
	return (exit_status);
}

void	set_exit(t_data *data)
{
	pthread_mutex_lock(&data->mtx_exit);
	data->exit = true;
	pthread_mutex_unlock(&data->mtx_exit);
}
