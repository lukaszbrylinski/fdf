/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:17:32 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 01:14:32 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**alloc_2d_array(int rows, int cols)
{
	int	**arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int *) * rows);
	if (!arr)
		return (NULL);
	while (i < rows)
	{
		arr[i] = malloc(sizeof(int) * cols);
		if (!arr[i])
			return (NULL);
		i++;
	}
	return (arr);
}

// void	fill_color_row(int *color_row, int *map_row, int width)
// {
// 	int	i;

// 	i = 0;
// 	while (i < width)
// 	{
// 		if (map_row[i] == 0)
// 			color_row[i] = 0xFFFFFF;
// 		else
// 			color_row[i] = 0xFF0000;
// 		i++;
// 	}
// }

void	fill_map_with_no_col_val(t_map *map, char *line, int index)
{
	int		i;
	char	**tokens;

	i = 0;
	
	tokens = ft_split(line, ' ');
	while (i < map->map_width)
	{
		map->map[index][i] = ft_atoi(tokens[i]);
		//printf("%d\n", map->map[index][i]);
		if (map->map[index][i] == 0)
			map->color_map[index][i] = 0xFFFFFF;
		else
			map->color_map[index][i] = 0xFF0000;
		i++;
	}
	free_arr(tokens);
}

void	fill_maps(t_map *map_data, char **lines, int if_color)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (if_color)
		{
			fill_map_with_col_val(map_data, lines[i], i);
		}
		else
		{
			fill_map_with_no_col_val(map_data, lines[i], i);
		}
		// fill_row(map_data->map[i], lines[i], map_data->map_width);
		// fill_color_row(map_data->color_map[i], map_data->map[i],
		// 	map_data->map_width);
		i++;
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
		//printf("no color\n");
		fill_maps(map_data, lines, 0);
	}
	else
	{
		//printf("color\n");
		fill_maps(map_data, lines, 1);
	}
		free_arr(lines);
	return (map_data);
}
