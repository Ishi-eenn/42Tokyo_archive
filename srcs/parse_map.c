/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:29:08 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/22 18:03:31 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return_error(OPEN_ERROR, 1);
	height = 0;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		return_error(CLOSE_ERROR, 1);
	return (height);
}

static int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return_error(OPEN_ERROR, 1);
	width = 0;
	if (get_next_line(fd, &line) == -1)
		return_error(MAP_ERROR, 0);
	if (*line == '\0')
		return_error(MAP_ERROR, 0);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) == -1)
		return_error(CLOSE_ERROR, 1);
	return (width);
}

static void	judge_map_max(int n)
{
	if (n > Z_MAX || n < -Z_MAX)
		return_error(MAP_ERROR, 0);
}

static void	fill_table(int **n, char *line, int width)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i] && i < width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			return_error(MALLOC_ERROR, 1);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = -1;
		free(num[i]);
		judge_map_max(n[i][0]);
	}
	if (i != width || num[i])
		return_error(MAP_ERROR, 0);
	free(num);
}

static void	get_z_min_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	check_valid(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->width = get_width(filename);
	map->height = get_height(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return_error(OPEN_ERROR, 1);
	i = -1;
	map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		return_error(MALLOC_ERROR, 1);
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		map->array[++i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			return_error(MALLOC_ERROR, 1);
		fill_table(map->array[i], line, map->width);
		free(line);
	}
	free(line);
	get_z_min_max(map);
	if (close(fd) == -1)
		return_error(CLOSE_ERROR, 1);
}
