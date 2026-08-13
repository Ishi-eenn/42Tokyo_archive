/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:54:01 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/03 01:49:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		result_length;
	va_list	args;

	i = 0;
	result_length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result_length += ft_judge_format(&args, str[i + 1]);
			i++;
		}
		else
			result_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result_length);
}

// #include <stdio.h>

// int main(void){
// 	char str[] = "Ishikawa";
// 	ft_printf("aaaa%c %c %c %c\n", 'A', 'B', 'C', 'D');
// 	ft_printf("%s\n", str);
// 	ft_printf("%p\n", &str[0]);
// 	// printf("%p\n", &str[0]);
// 	ft_printf("%d\n", 2147483647);
// 	ft_printf("%u\n", 4294967295);
// 	ft_printf("%i\n", 1 + 1);
// 	ft_printf("%x\n", 10);
// 	ft_printf("%X\n", 255);

// 	printf("%d %c %s %p\n", 1, '1', "11", &str[3]);
// 	return (0);
// }
