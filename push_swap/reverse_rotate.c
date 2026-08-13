/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:44:14 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:11:21 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_reverse_rotate_a(t_arg *arg)
{
	t_node	*node;

	if (arg->a->size < 2)
		return (0);
	node = arg->a->bottom;
	arg->a->bottom->next->prev = 0;
	arg->a->bottom = arg->a->bottom->next;
	arg->a->size--;
	ft_push(arg->a, node);
	return (1);
}

static int	ft_reverse_rotate_b(t_arg *arg)
{
	t_node	*node;

	if (arg->b->size < 2)
		return (0);
	node = arg->b->bottom;
	arg->b->bottom->next->prev = 0;
	arg->b->bottom = arg->b->bottom->next;
	arg->b->size--;
	ft_push(arg->b, node);
	return (1);
}

int	ft_judge_reverse_rotate(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		result = ft_reverse_rotate_a(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("rra\n", 1);
	}
	if (type == 'b')
	{
		result = ft_reverse_rotate_b(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("rrb\n", 1);
	}
	if (type == 'r')
	{
		result = ft_reverse_rotate_a(arg) + ft_reverse_rotate_b(arg);
		if (result == 2 && print)
			ft_putstr_fd("rrr\n", 1);
	}
	return (1);
}
