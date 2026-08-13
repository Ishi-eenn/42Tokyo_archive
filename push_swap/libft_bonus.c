/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:55:17 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:28:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isspace(char c)
{
	if ((c <= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff_s1;
	unsigned char	*buff_s2;

	i = 0;
	buff_s1 = (unsigned char *)s1;
	buff_s2 = (unsigned char *)s2;
	while (i < n && buff_s1[i] != '\0' && (buff_s1[i] == buff_s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((int)(buff_s1[i] - buff_s2[i]));
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
