/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:48:51 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:23:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_rotate_a(t_arg *arg)
{
	t_node	*node;

	if (arg->a->size < 2)
		return (0);
	node = ft_pop(arg->a);
	ft_pushback(arg->a, node);
	return (1);
}

static int	ft_rotate_b(t_arg *arg)
{
	t_node	*node;

	if (arg->b->size < 2)
		return (0);
	node = ft_pop(arg->b);
	ft_pushback(arg->b, node);
	return (1);
}

int	ft_judge_rotate(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		result = ft_rotate_a(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("ra\n", 1);
	}
	if (type == 'b')
	{
		result = ft_rotate_b(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("rb\n", 1);
	}
	if (type == 'r')
	{
		result = ft_rotate_a(arg) + ft_rotate_b(arg);
		if (result == 2 && print != 0)
			ft_putstr_fd("rr\n", 1);
	}
	return (1);
}
