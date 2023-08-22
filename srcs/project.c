/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:29:13 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/22 22:25:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project(int x, int y, t_fdf *env)
{
	t_point	point;

	point.z = env->map->array[y][x][0];
	if (env->map->array[y][x][1] >= 0)
		point.color = env->map->array[y][x][1];
	else
		point.color = set_default_color(env->map->array[y][x][0]);
	point.x = x * env->camera->zoom;
	point.y = y * env->camera->zoom;
	point.z *= env->camera->zoom / env->camera->z_height;
	point.x -= (env->map->width * env->camera->zoom) / 2;
	point.y -= (env->map->height * env->camera->zoom) / 2;
	rotate_x(&point.y, &point.z, env->camera->x_angle);
	rotate_y(&point.x, &point.z, env->camera->y_angle);
	rotate_z(&point.x, &point.y, env->camera->z_angle);
	point.x += WIDTH / 2 + env->camera->x_offset;
	point.y += (HEIGHT + env->map->height / 2 * env->camera->zoom) / 2
		+ env->camera->y_offset;
	point.reverse = 0;
	return (point);
}
