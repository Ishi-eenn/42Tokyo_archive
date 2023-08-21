/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:29:33 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/21 09:17:29 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "color_define.h"
# include "key_define.h"
# include "struct_define.h"
# include "get_next_line.h"
# include "error_message.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1080
# define HEIGHT 620

// init
t_fdf	*env_init(const char *path);
t_camera	*camera_init(t_fdf *env);
t_map	*ft_map_init(void);

void	check_valid(char *filename, t_map *map);
void	draw(t_map *map, t_fdf *env);
void	ft_put_pixel(t_fdf *env, int x, int y, int color);
void	draw_line(t_point s, t_point e, t_fdf *env);
t_point	project(int x, int y, t_fdf *env);
int		ft_min(int a, int b);
int		get_default_color(int z, t_map *map);
void	return_error(const char *err_msg, int system_function);
double	ft_reset_angles(double angle);

float	ft_abs(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);

void	hook_controls(t_fdf *env);
int		key_press_controls(int keycode, void *params);
int		ft_mouse_down(int button, int x, int y, void *params);
int		ft_mouse_up(int button, int x, int y, void *params);
int		ft_mouse_move(int x, int y, void *params);
int		ft_close_win(void *params);

#endif
