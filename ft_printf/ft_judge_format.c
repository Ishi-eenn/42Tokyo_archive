/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judge_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:54:03 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/03 01:51:24 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_judge_format(va_list *data, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(*data, int));
	if (format == 's')
		print_len += ft_putstr(va_arg(*data, char *));
	if (format == 'p')
		print_len += ft_putptr(va_arg(*data, uintptr_t));
	if (format == 'd')
		print_len += ft_putnbr(va_arg(*data, int));
	if (format == 'i')
		print_len += ft_putnbr(va_arg(*data, int));
	if (format == 'u')
		print_len += ft_putunbr(va_arg(*data, unsigned int));
	if (format == 'x')
		print_len += ft_lowercase_puthex(va_arg(*data, unsigned int));
	if (format == 'X')
		print_len += ft_uppercase_puthex(va_arg(*data, unsigned int));
	if (format == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}
