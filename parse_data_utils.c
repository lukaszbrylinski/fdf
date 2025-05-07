/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:21:46 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/07 18:10:28 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_columns(char *line)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_split(line, ' ');
	while (split[count])
		count++;
	free_split(split);
	return count;
}

int	*parse_line_to_ints(char *line, int columns)
{
	int		*row;
	char	**split;
	int		i;

	i = 0;
	row = malloc(sizeof(int) * columns);
	if (!row)
		return (row);
	split = ft_split(line, ' ');
	while (i++ < columns)
		row[i-1] = ft_atoi(split[i-1]);
	free_split(split);
	return (row);
}

int	**allocate_matrix(int capacity)
{
	int **matrix;

	matrix = malloc(sizeof(int *) * capacity);
	return (matrix);
}

int	handle_first_line(int fd, int **matrix, int *columns)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	*columns = count_columns(line);
	matrix[rows] = parse_line_to_ints(line, *columns);
	free(line);
	return (++rows);
}

int	resize_matrix(int ***matrix, int *capacity)
{
	int **new_matrix;
	int i;

	*capacity *= 2;
	new_matrix = malloc(sizeof(int *) * (*capacity));
	i = 0;
	if (!new_matrix)
		return (0);
	while (i < (*capacity / 2))
	{
		new_matrix[i] = (*matrix)[i];
		i++;
	}	
	free(*matrix);
	*matrix = new_matrix;
	return (1);
}
