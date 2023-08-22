/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:41:03 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/22 22:45:10 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_default_color(int z)
{
	if (z < 0)
	return (COLOR_MINUS);
	if (z > 0)
		return (COLOR_PLUS);
	return (COLOR_ZERO);
}
