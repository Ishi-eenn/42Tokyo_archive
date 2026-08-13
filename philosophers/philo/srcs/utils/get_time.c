/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:45:44 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/20 11:51:07 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

u_int64_t	get_time(u_int64_t relative)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * (u_int64_t)1000) + (now.tv_usec / 1000) - relative);
}
