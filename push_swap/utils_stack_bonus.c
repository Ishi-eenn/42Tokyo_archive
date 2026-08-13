/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:52:15 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:46:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*ft_lstnew(int data)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (ret == NULL)
		return (NULL);
	ret->data = data;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

t_stack	*ft_stacknew(void)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (ret == NULL)
		return (NULL);
	ret->top = NULL;
	ret->bottom = NULL;
	ret->size = 0;
	return (ret);
}

void	ft_pushback(t_stack *stack, t_node *node)
{
	if (node == NULL)
		return ;
	if (stack->size != 0)
	{
		node->prev = NULL;
		node->next = stack->bottom;
		stack->bottom->prev = node;
		stack->bottom = node;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

void	ft_push(t_stack *stack, t_node *node)
{
	if (node == NULL)
		return ;
	if (stack->size == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->next = node;
		node->next = NULL;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->size++;
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*ret;

	if (stack->size == 0)
		return (0);
	if (stack->size == 1)
	{
		ret = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		ret = stack->top;
		stack->top->prev->next = NULL;
		stack->top = stack->top->prev;
	}
	stack->size--;
	return (ret);
}
