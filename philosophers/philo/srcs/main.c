/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:27:08 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 08:52:36 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!input_data_from_cmd_line(&data, argc, argv))
		return (1);
	if (!init_table(&data))
		return (1);
	if (!dining(&data))
	{
		delete_table(&data);
		return (1);
	}
	delete_table(&data);
	return (0);
}
