/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 01:20:29 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/21 02:18:55 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*env_init(const char *path)
{
	t_fdf	*env;
	char	*title;

	title = ft_strjoin("FdF - ", path);
	env = malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error(MALLOC_ERROR, 1);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error(MLX_ERROR, 1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (!env->win)
		ft_return_error(MLX_ERROR, 1);
	free(title);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error(MLX_ERROR, 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
	env->camera = NULL;
	env->mouse = malloc(sizeof(t_mouse));
	if (!env->mouse)
		ft_return_error(MALLOC_ERROR, 1);
	return (env);
}

t_camera	*ft_camera_init(t_fdf *env)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		ft_return_error(MALLOC_ERROR, 1);
	camera->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	camera->x_angle = -0.6157;
	camera->y_angle = -0.5299;
	camera->z_angle = 0.6157;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}

t_map	*ft_map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_return_error(MALLOC_ERROR, 1);
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}
