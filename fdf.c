/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:29:25 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/23 09:53:42 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void judge_filename(char *str){
	int len = ft_strlen(str) - 1;
	int judge = ft_strncmp(&str[len - 3], ".fdf", 4);
	// printf("%s\n", &str[len - 3]);
	// printf("-----------%d-------------\n", judge);
	if(judge != 0)
		return_error("お前、Makefile入れただろ。", 0);
}

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		judge_filename(argv[1]);
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

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fdf");
// }
