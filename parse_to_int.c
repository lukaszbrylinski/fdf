/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:21:32 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/15 15:12:39 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_string_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

char	**read_lines_from_file(const char *filename, int *row_count)
{
	int		fd;
	char	**lines;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * 100);
	if (!lines)
		return (NULL);
	line = get_next_line(fd);
	while (line && i < 100)
	{
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	if (row_count)
		*row_count = i;
	return (lines);
}

int	*parse_line_to_ints(char *line, int *width)
{
	char	**tokens;
	int		*row;
	int		count;
	int		i;

	count = 0;
	tokens = ft_split(line, ' ');
	while (tokens[count])
		count++;
	row = malloc(sizeof(int) * count);
	if (!row)
		return (NULL);
	*width = count;
	i = 0;
	while (i < count)
	{
		row[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_string_array(tokens);
	return (row);
}

int	**parse_lines_to_int_array(char **lines, int row_count, int *cols)
{
	int	**grid;
	int	width;
	int	i;

	width = 0;
	i = 0;
	grid = malloc(sizeof(int *) * row_count);
	if (!grid)
		return (NULL);
	while (i < row_count)
	{
		grid[i] = parse_line_to_ints(lines[i], &width);
		i++;
	}
	if (cols)
		*cols = width;
	return (grid);
}

int	**parse_file_to_int_array(const char *filename, int *rows, int *cols)
{
	char	**lines;
	int		row_count;
	int		**grid;

	lines = read_lines_from_file(filename, &row_count);
	if (!lines)
		return (NULL);
	grid = parse_lines_to_int_array(lines, row_count, cols);
	free_string_array(lines);
	if (rows)
		*rows = row_count;
	return (grid);
}
