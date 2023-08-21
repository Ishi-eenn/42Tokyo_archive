/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:28:53 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/21 12:59:12 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_value(t_fdf *env)
{
	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
	if (env->camera->iso)
	{
		env->camera->x_angle = -0.6157;
		env->camera->y_angle = -0.5299;
		env->camera->z_angle = 0.6157;
	}
	else
	{
		env->camera->x_angle = 0;
		env->camera->y_angle = 0;
		env->camera->z_angle = 0;
	}
	env->camera->z_height = 1;
	env->camera->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
}

static void	change_projection(t_fdf *env)
{
	if (env->camera->iso)
	{
		env->camera->x_angle = 0;
		env->camera->y_angle = 0;
		env->camera->z_angle = 0;
	}
	else
	{
		env->camera->x_angle = -0.6157;
		env->camera->y_angle = -0.5299;
		env->camera->z_angle = 0.6157;
	}
	env->camera->iso = !env->camera->iso;
}

static void	height_control(int keycode, t_fdf *env)
{
	if (keycode == MINUS)
		env->camera->z_height += 0.1;
	else if (keycode == PLUS)
		env->camera->z_height -= 0.1;
	if (env->camera->z_height < 0.1)
		env->camera->z_height = 0.1;
	else if (env->camera->z_height > 10)
		env->camera->z_height = 10;
}

static void	translate_control(int keycode, t_fdf *env)
{
	if (keycode == ARROW_LEFT)
		env->camera->x_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		env->camera->x_offset += 10;
	else if (keycode == ARROW_DOWN)
		env->camera->y_offset += 10;
	else if (keycode == ARROW_UP)
		env->camera->y_offset -= 10;
}

int	key_press_controls(int keycode, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (keycode == ARROW_DOWN || keycode == ARROW_LEFT || keycode == ARROW_UP
		|| keycode == ARROW_RIGHT)
		translate_control(keycode, env);
	else if (keycode == MINUS || keycode == PLUS)
		height_control(keycode, env);
	else if (keycode == SPACE)
		change_projection(env);
	else if (keycode == KEY_R)
		reset_value(env);
	else if (keycode == ESCAPE)
		close_win(env);
	draw(env->map, env);
	return (0);
}
