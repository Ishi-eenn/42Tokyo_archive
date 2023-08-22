/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:29:19 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/22 22:20:53 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *env, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bpp / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

void	get_z_min_max(t_map *map, int n)
{
	if (n > map->z_max)
		map->z_max = n;
	if (n < map->z_min)
		map->z_min = n;
}

void	return_error(const char *err_msg, int system_function)
{
	if (!system_function)
		ft_putendl_fd((char *)err_msg, STDERR_FILENO);
	else
		perror(err_msg);
	exit(-1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	set_default_color(int z)
{
	if (z == 0)
		return (0xf6f9fc);
	if (z > 0)
		return (0x438bc3);
	return (0x86505d);
}
