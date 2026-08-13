/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:55:37 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:41:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_stack;

typedef struct s_arg
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				pivot[2];
}	t_arg;

t_node	*ft_lstnew(int data);
void	ft_push(t_stack *stack, t_node *node);
t_node	*ft_pop(t_stack *stack);
t_stack	*ft_stacknew(void);
int		ft_judge_swap(t_arg *arg, char type, int print);
int		ft_judge_push(t_arg *arg, char type, int print);
int		ft_judge_rotate(t_arg *arg, char type, int print);
int		ft_judge_reverse_rotate(t_arg *arg, char type, int print);
void	ft_print_error(t_arg *arg);
void	ft_pushback(t_stack *stack, t_node *node);
void	ft_free(t_arg *arg);
void	ft_sort(t_arg *arg);
void	ft_sort_three(t_arg *arg);
void	ft_sort_four(t_arg *arg);
void	ft_sort_five(t_arg *arg);
void	ft_get_stack_args(t_arg *arg, int ac, char **av);
void	ft_check_sorted(t_arg *arg);
void	ft_check_overlap(t_arg *arg);
void	ft_sort_two(t_arg *arg, char type);
int		ft_find_five_mid(t_stack *stack);
int		ft_abs(int data);
int		ft_stack_find(t_stack *stack, int data);
int		ft_get_stack_min(t_stack *stack);
int		ft_get_stack_max(t_stack *stack);
void	ft_rotate_indiv(t_arg *arg, int count, char type);
void	ft_rotate_all(t_arg *arg, int ra_cnt, int rb_cnt);
void	ft_get_pivot(t_arg *arg);
void	ft_last_rotate(t_arg *arg);
int		ft_find_index(t_arg *arg, int data);
int		ft_isspace(char c);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

#endif
