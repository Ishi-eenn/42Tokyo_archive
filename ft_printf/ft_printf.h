/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:53:58 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/03 03:49:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_judge_format(va_list *data, const char format);
int	ft_lowercase_puthex(unsigned int nb);
int	ft_uppercase_puthex(unsigned int nb);
int	ft_putptr(uintptr_t nb);

#endif
