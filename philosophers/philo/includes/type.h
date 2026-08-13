/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:47:01 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 09:49:48 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_data		t_data;

typedef struct s_philo		t_philo;
struct s_philo
{
	int				id;
	int				eat_count;
	u_int64_t		time_last_eaten;
	pthread_mutex_t	*mtx_fork_l;
	pthread_mutex_t	*mtx_fork_r;
	pthread_mutex_t	mtx_eat_count;
	pthread_mutex_t	mtx_time_last_eaten;
	t_data			*data;
};

struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_limit;
	bool			exit;
	u_int64_t		time_start;
	t_philo			*philos;
	pthread_mutex_t	mtx_exit;
	pthread_mutex_t	mtx_printf;
	pthread_mutex_t	*mtx_forks;
	pthread_t		*threads;
	pthread_t		monitor_death;
	pthread_t		monitor_eat_limit;
};

#endif
