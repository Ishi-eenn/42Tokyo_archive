/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:17:10 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:36:28 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*to_free;

	node = stack->top;
	while (node != NULL)
	{
		to_free = node;
		node = node->prev;
		free(to_free);
	}
}

void	ft_free(t_arg *arg)
{
	if (arg == NULL)
		return ;
	if (arg->a != NULL)
	{
		if (arg->a->size != 0)
			free_stack(arg->a);
		free(arg->a);
	}
	if (arg->b != NULL)
	{
		if (arg->b->size != 0)
			free_stack(arg->b);
		free(arg->b);
	}
	free(arg);
}
