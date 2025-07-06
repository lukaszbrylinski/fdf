/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:17:32 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 03:47:09 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_color_map(t_map *map, int min)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map[i][j] == min)
				map->color_map[i][j] = 0xFFFFFF;
			else
				map->color_map[i][j] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void	fill_map_with_no_col_val(t_map *map, char **lines)
{
	int		i;
	int		j;
	char	**tokens;
	int		min;

	i = 0;
	min = INT_MAX;
	while (i < map->map_height)
	{
		j = 0;
		tokens = ft_split(lines[i], ' ');
		while (j < map->map_width)
		{
			map->map[i][j] = ft_atoi(tokens[j]);
			if ((min > map->map[i][j]) || (i == 0 && j == 0))
				min = map->map[i][j];
			j++;
		}
		free_arr(tokens);
		i++;
	}
	add_min_value_to_map(map, min);
	fill_color_map(map, min);
}

void	fill_maps(t_map *map_data, char **lines, int if_color)
{
	if (if_color)
	{
		fill_map_with_col_val(map_data, lines);
	}
	else
	{
		fill_map_with_no_col_val(map_data, lines);
	}
}

char	**read_lines(int fd, int *out_count, int cap)
{
	char	**lines;
	char	*line;
	int		count;

	cap = 8;
	count = 0;
	lines = malloc(sizeof(char *) * cap);
	if (!lines)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (count >= cap)
		{
			lines = resize_lines(lines, cap, cap * 2);
			cap *= 2;
			if (!lines)
				return (NULL);
		}
		lines[count++] = line;
		line = get_next_line(fd);
	}
	lines[count] = NULL;
	*out_count = count;
	return (lines);
}

t_map	*parse_map(int fd)
{
	t_map	*map_data;
	char	**lines;
	int		height;
	int		width;

	lines = read_lines(fd, &height, 8);
	if (!lines || !lines[0])
		return (NULL);
	width = count_columns(lines[0]);
	map_data = malloc(sizeof(t_map));
	map_data->map_height = height;
	map_data->map_width = width;
	map_data->map = alloc_2d_array(height, width);
	map_data->color_map = alloc_2d_array(height, width);
	if (!ft_strchr(lines[0], ','))
	{
		fill_maps(map_data, lines, 0);
	}
	else
	{
		fill_maps(map_data, lines, 1);
	}
	free_arr(lines);
	return (map_data);
}
