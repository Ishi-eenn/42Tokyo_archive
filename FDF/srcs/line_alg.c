/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:28:58 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/23 05:50:41 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.reverse)
	{
		r = lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	draw_line_loop(t_point s, t_point e, float gradient, t_fdf *env)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->steep)
		{
			put_pixel(env, ft_ftoi(inter_y), x,
				get_color(x, s, e, ft_rfpart(inter_y)));
			put_pixel(env, ft_ftoi(inter_y) + 1, x,
				get_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			put_pixel(env, x, ft_ftoi(inter_y),
				get_color(x, s, e, ft_rfpart(inter_y)));
			put_pixel(env, x, ft_ftoi(inter_y) + 1,
				get_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

void	draw_line(t_point s, t_point e, t_fdf *env)
{
	float	dy;
	float	dx;
	float	gradient;

	env->steep = ft_abs(e.y - s.y) > ft_abs(e.x - s.x);
	if (env->steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	draw_line_loop(s, e, gradient, env);
}
