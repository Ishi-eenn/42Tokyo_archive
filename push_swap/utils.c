/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:09:43 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:44:59 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(t_arg *arg)
{
	write(1, "Error\n", 6);
	ft_free(arg);
	exit(1);
}

int	ft_abs(int data)
{
	if (data < 0)
		return (data * (-1));
	return (data);
}

void	ft_get_pivot(t_arg *arg)
{
	t_node	*node;
	t_node	*comp;
	int		count;

	node = arg->a->top;
	while (node)
	{
		comp = arg->a->top;
		count = 0;
		while (comp)
		{
			if (node->data > comp->data)
				count++;
			comp = comp->prev;
		}
		if (count == arg->a->size / 3)
			arg->pivot[0] = node->data;
		if (count == (arg->a->size * 2) / 3)
			arg->pivot[1] = node->data;
		node = node->prev;
	}
}
