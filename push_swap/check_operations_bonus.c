/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:57:47 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:35:06 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_push(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 3 && ft_strncmp(line, "pa\n", 3) == 0)
	{
		ft_judge_push(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "pb\n", 3) == 0)
	{
		ft_judge_push(arg, 'b', 0);
		ret = 1;
	}
	return (ret);
}

int	ft_check_swap(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 3 && ft_strncmp(line, "sa\n", 3) == 0)
	{
		ft_judge_swap(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "sb\n", 3) == 0)
	{
		ft_judge_swap(arg, 'b', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "ss\n", 3) == 0)
	{
		ft_judge_swap(arg, 's', 0);
		ret = 1;
	}
	return (ret);
}

int	ft_check_rotate(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 3 && ft_strncmp(line, "ra\n", 3) == 0)
	{
		ft_judge_rotate(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "rb\n", 3) == 0)
	{
		ft_judge_rotate(arg, 'b', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "rr\n", 3) == 0)
	{
		ft_judge_rotate(arg, 'r', 0);
		ret = 1;
	}
	return (ret);
}

int	ft_check_reverse_rotate(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rra\n", 4) == 0)
	{
		ft_judge_reverse_rotate(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rrb\n", 4) == 0)
	{
		ft_judge_reverse_rotate(arg, 'b', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rrr\n", 4) == 0)
	{
		ft_judge_reverse_rotate(arg, 'r', 0);
		ret = 1;
	}
	return (ret);
}
