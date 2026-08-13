/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:49:43 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:32:38 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sorted(t_arg *arg)
{
	t_node	*node;

	node = arg->a->top;
	while (node->prev)
	{
		if (node->data > node->prev->data)
			return ;
		node = node->prev;
	}
	exit(0);
}

void	ft_check_overlap(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	node1 = arg->a->top;
	while (node1 != NULL)
	{
		node2 = node1->prev;
		while (node2 != NULL)
		{
			if (node1->data == node2->data)
				ft_print_error(arg);
			node2 = node2->prev;
		}
		node1 = node1->prev;
	}
}
