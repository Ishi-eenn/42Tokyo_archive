/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:04:32 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 12:03:32 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# include "type.h"

// exit.c
bool		is_exit(t_data *data);
void		set_exit(t_data *data);

// ft_putchar_fd.c
void		ft_putchar_fd(char c, int fd);

// ft_putstr_fd.c
void		ft_putstr_fd(char *str, int fd);

// ft_isdigit.c
int			ft_isdigit(int c);

// ft_strtol.c
long		ft_strtol(char *str);

// ft_atoi.c
int			ft_atoi(char *str);

// get_tie.c
u_int64_t	get_time(u_int64_t relative);

// print.c
void		print_error(char *str);
void		print_state(t_philo *philo, const char *state);

// wait.c
void		ft_wait(u_int64_t ms);

#endif
