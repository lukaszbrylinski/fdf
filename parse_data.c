/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:11:04 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/07 17:30:18 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**read_fdf_to_matrix(const char *filename,
	int *rows_out, int *cols_out, int fd)
{
	int		capacity;
	int		rows;
	int		columns;
	int		**matrix;
	char	*line;

	fd = open(filename, O_RDONLY);
	capacity = 128;
	rows = 0;
	matrix = allocate_matrix(capacity);
	rows = handle_first_line(fd, matrix, &columns);
	if (fd < 0 || rows < 0)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		if (rows >= capacity)
			resize_matrix(&matrix, &capacity);
		matrix[rows++] = parse_line_to_ints(line, columns);
		free(line);
	}
	close(fd);
	*rows_out = rows;
	*cols_out = columns;
	return (matrix);
}
