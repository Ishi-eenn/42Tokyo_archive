/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:55:57 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/03 01:54:35 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_rec_putptr(uintptr_t nb)
{
	while (nb >= 16)
	{
		ft_rec_putptr(nb / 16);
		nb %= 16;
	}
	ft_lowercase_puthex(nb);
}

int	ft_putptr(uintptr_t nb)
{
	write(1, "0x", 2);
	ft_rec_putptr(nb);
	return (ft_ptrlen(nb) + 2);
}
