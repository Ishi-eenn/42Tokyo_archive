/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:45:16 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 08:58:41 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stdlib.h>

# include "type.h"
# include "utils.h"

# define ERR_MALLOC "Malloc fail\n"
# define ERR_MTX_INIT "pthread_mutex_init fail\n"

// data_structures.c
bool	init_data_structures_and_check(t_data *data);

// last_eaten_times.c
void	init_last_eaten_times(t_data *data);

// mutex.c
bool	init_mutex_and_check(t_data *data);

// philo.c
bool	init_philo_and_check(t_data *data);

// table.c
bool	init_table(t_data *data);
void	delete_table(t_data *data);

#endif
