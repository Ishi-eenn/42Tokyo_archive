/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:45:50 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/24 11:42:42 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

int		ft_check_push(t_arg *arg, char *line);
int		ft_check_swap(t_arg *arg, char *line);
int		ft_check_rotate(t_arg *arg, char *line);
int		ft_check_reverse_rotate(t_arg *arg, char *line);
void	ft_free(t_arg *arg);
void	ft_get_stack_args(t_arg *arg, int ac, char **av);
void	ft_check_overlap(t_arg *arg);
int		ft_isspace(char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_judge_push(t_arg *arg, char type, int print);
int		ft_judge_reverse_rotate(t_arg *arg, char type, int print);
int		ft_judge_rotate(t_arg *arg, char type, int print);
int		ft_judge_swap(t_arg *arg, char type, int print);
t_node	*ft_lstnew(int data);
t_stack	*ft_stacknew(void);
void	ft_pushback(t_stack *stack, t_node *node);
void	ft_push(t_stack *stack, t_node *node);
t_node	*ft_pop(t_stack *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	ft_print_error(t_arg *arg);

#endif
