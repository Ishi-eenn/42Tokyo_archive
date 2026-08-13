/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:01:57 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:34:53 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	print_exit(char *str, int status)
{
	ft_putstr_fd(str, 1);
	exit(status);
}

static void	ft_check_sorted(t_arg *arg)
{
	t_node	*node;
	int		flag;

	node = arg->a->top;
	flag = 1;
	while (node->prev != NULL)
	{
		if (node->data > node->prev->data)
		{
			flag = 0;
			break ;
		}
		node = node->prev;
	}
	ft_free(arg);
	if (flag)
		print_exit("OK\n", 0);
	else
		print_exit("KO\n", 0);
	exit(0);
}

void	ft_print_error(t_arg *arg)
{
	ft_putstr_fd("Error\n", 2);
	ft_free(arg);
	exit(1);
}

static void	ft_do_sort(t_arg *arg)
{
	char	*line;
	int		result;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			ft_check_sorted(arg);
		result = ft_check_push(arg, line) + ft_check_swap(arg, line)
			+ ft_check_rotate(arg, line) + ft_check_reverse_rotate(arg, line);
		free(line);
		if (result != 1)
			ft_print_error(arg);
	}
}

int	main(int ac, char **av)
{
	t_arg	*arg;

	if (ac <= 1)
		return (0);
	arg = (t_arg *)malloc(sizeof(t_arg));
	if (arg == NULL)
		ft_print_error(arg);
	arg->a = ft_stacknew();
	arg->b = ft_stacknew();
	if (arg->a == NULL || arg->b == NULL)
		ft_print_error(arg);
	ft_get_stack_args(arg, ac, av);
	ft_check_overlap(arg);
	ft_do_sort(arg);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q checker");
// }
