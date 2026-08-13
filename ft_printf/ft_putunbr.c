/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:56:35 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/03 03:27:33 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsignedintlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned int nb)
{
	unsigned int	n;

	n = nb;
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (ft_unsignedintlen(nb));
}

