/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:42:52 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 19:15:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINING_H
# define DINING_H

# include <stdbool.h>
# include <sys/time.h>

# include "utils.h"
# include "philo.h"

# define ERR_PTHRED "pthread_create fail\n"

// create_death_monitor_thread.c
bool	create_death_monitor_thread_and_check(t_data *data);

// create_eat_limit_monitor_thread.c
bool	create_eat_limit_monitor_thread_and_check(t_data *data);

// create_philosopher_threads.c
bool	create_philosopher_threads_and_check(t_data *data);

// cutlery.c
void	take_forks(t_philo *philo);
void	put_forks(t_philo *philo);

// cycle.c
bool	eating_cycle(t_philo *philo);
bool	sleeping_cycle(t_philo *philo);
void	thinking_cycle(t_philo *philo);

// death.c
void	*monitor_death(void *arg);

// dining.c
bool	dining(t_data *data);

// eat.c
void	set_time_last_eaten(t_philo *philo);
void	increment_eat_count(t_philo *philo);
int		get_eat_count(t_philo *philo);
void	*monitor_eat_count_limit(void *arg);

// routine.c
void	*routine(void *arg);

#endif
