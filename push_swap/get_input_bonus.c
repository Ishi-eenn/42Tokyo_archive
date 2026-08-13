/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:55:15 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:38:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_atoc(const char *str, t_arg *arg, int *index)
{
	int			sign;
	int			len;
	long long	result;

	sign = 1;
	len = 0;
	if (str[*index] == '-' || str[*index] == '+')
		if (str[(*index)++] == '-')
			sign *= -1;
	result = 0;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10 + (str[(*index)++] - '0');
		len++;
	}
	result = result * (sign);
	if (len > 10 || result < INT_MIN || result > INT_MAX || len == 0)
		ft_print_error(arg);
	return ((int)result);
}

static void	ft_judge_pb(const char *str, t_arg *arg, int *index)
{
	t_node	*buff;

	buff = ft_lstnew(ft_atoc(str, arg, index));
	if (buff == NULL)
		ft_print_error(arg);
	ft_pushback(arg->a, buff);
}

static void	ft_get_str(t_arg *arg, char *str)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && ft_isspace(str[j]) != 0)
			j++;
		if (str[j] == '\0' && flag == 1)
			break ;
		if ((str[j] == '\0' && flag == 0))
			ft_print_error(arg);
		if (ft_isdigit(str[j]) == 0 && str[j] != '-' && str[j] != '+')
			ft_print_error(arg);
		ft_judge_pb(str, arg, &j);
		if (ft_isspace(str[j]) == 0 && str[j] != '\0')
			ft_print_error(arg);
		flag = 1;
	}
	if (j == 0)
		ft_print_error(arg);
}

void	ft_get_stack_args(t_arg *arg, int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	while (++i < ac)
	{
		str = av[i];
		ft_get_str(arg, str);
	}
}
