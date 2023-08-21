/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:29:25 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/21 09:17:29 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		env = env_init(argv[1]);
		env->map = ft_map_init();
		check_valid(argv[1], env->map);
		env->camera = camera_init(env);
		hook_controls(env);
		draw(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		return_error(USAGE_ERROR, 0);
}

__attribute__((destructor)) static void destructor()
{
    system("leaks -q fdf");
}
