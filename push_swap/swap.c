/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:04:04 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:05:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap_a(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	if (arg->a->size < 2)
		return (0);
	node1 = ft_pop(arg->a);
	node2 = ft_pop(arg->a);
	ft_push(arg->a, node1);
	ft_push(arg->a, node2);
	return (1);
}

static int	ft_swap_b(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	if (arg->b->size < 2)
		return (0);
	node1 = ft_pop(arg->b);
	node2 = ft_pop(arg->b);
	ft_push(arg->b, node1);
	ft_push(arg->b, node2);
	return (1);
}

int	ft_judge_swap(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		result = ft_swap_a(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("sa\n", 1);
	}
	if (type == 'b')
	{
		result = ft_swap_b(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("sb\n", 1);
	}
	if (type == 's')
	{
		result = ft_swap_a(arg) + ft_swap_b(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("ss\n", 1);
	}
	return (0);
}
