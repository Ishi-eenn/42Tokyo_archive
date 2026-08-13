/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:58:52 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:08:08 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_rotate_num(t_arg *arg, int *a_cnt, int *b_cnt)
{
	t_node	*node;
	int		a_index;
	int		b_index;
	int		i;

	node = arg->b->top;
	i = 0;
	while (i < arg->b->size)
	{
		a_index = ft_find_index(arg, node->data);
		if (i >= (arg->b->size + 1) / 2)
			b_index = (arg->b->size - i) * (-1);
		else
			b_index = i;
		if (i == 0 || ft_abs(*a_cnt) + ft_abs(*b_cnt)
			> ft_abs(a_index) + ft_abs(b_index))
		{
			*a_cnt = a_index;
			*b_cnt = b_index;
		}
		node = node->prev;
		i++;
	}
}

void	ft_rotate_indiv(t_arg *arg, int count, char type)
{
	while (count)
	{
		if (count > 0)
		{
			ft_judge_rotate(arg, type, 1);
			count--;
		}
		if (count < 0)
		{
			ft_judge_reverse_rotate(arg, type, 1);
			count++;
		}
	}
}

void	ft_rotate_all(t_arg *arg, int ra_cnt, int rb_cnt)
{
	while (ra_cnt > 0 && rb_cnt > 0)
	{
		ft_judge_rotate(arg, 'r', 1);
		ra_cnt--;
		rb_cnt--;
	}
	while (ra_cnt < 0 && rb_cnt < 0)
	{
		ft_judge_reverse_rotate(arg, 'r', 1);
		ra_cnt++;
		rb_cnt++;
	}
	ft_rotate_indiv(arg, ra_cnt, 'a');
	ft_rotate_indiv(arg, rb_cnt, 'b');
}

static void	ft_a_to_b_until_5(t_arg *arg)
{
	int		i;
	int		size;
	t_node	*node;

	i = 0;
	size = arg->a->size;
	ft_get_pivot(arg);
	while (i < size && arg->a->size > 5)
	{
		node = arg->a->top;
		if (node->data <= arg->pivot[1])
		{
			ft_judge_push(arg, 'b', 1);
			if (node->data <= arg->pivot[0])
				ft_judge_rotate(arg, 'b', 1);
		}
		else
			ft_judge_rotate(arg, 'a', 1);
		i++;
	}
	while (arg->a->size > 5)
		ft_judge_push(arg, 'b', 1);
}

void	ft_sort(t_arg *arg)
{
	int		a_cnt;
	int		b_cnt;

	ft_a_to_b_until_5(arg);
	if (arg->a->size == 2)
		ft_sort_two(arg, 'a');
	else if (arg->a->size == 3)
		ft_sort_three(arg);
	else if (arg->a->size == 4)
		ft_sort_four(arg);
	else if (arg->a->size == 5)
		ft_sort_five(arg);
	while (arg->b->size)
	{
		a_cnt = 0;
		b_cnt = 0;
		ft_get_rotate_num(arg, &a_cnt, &b_cnt);
		ft_rotate_all(arg, a_cnt, b_cnt);
		ft_judge_push(arg, 'a', 1);
	}
	ft_last_rotate(arg);
}
