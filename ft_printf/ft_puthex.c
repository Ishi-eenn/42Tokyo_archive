/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:37:05 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/03 01:53:18 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int nb)
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

int	ft_lowercase_puthex(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	while (nb >= 16)
	{
		ft_lowercase_puthex(nb / 16);
		nb %= 16;
	}
	ft_putchar("0123456789abcdef"[nb]);
	return (ft_hexlen(n));
}

int	ft_uppercase_puthex(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	while (nb >= 16)
	{
		ft_uppercase_puthex(nb / 16);
		nb %= 16;
	}
	ft_putchar("0123456789ABCDEF"[nb]);
	return (ft_hexlen(n));
}
