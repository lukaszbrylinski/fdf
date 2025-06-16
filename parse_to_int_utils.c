/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_int_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:52:00 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/15 16:00:55 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dimensions_from_file(const char *filename, int *rows, int *cols)
{
	char	**lines;
	int		row_count;
	int		col_count;
	int		temp_cols;
	int		*first_line;
	int		*temp_line;
	int		i;

	row_count = 0;
	col_count = 0;
	lines = read_lines_from_file(filename, &row_count);
	if (!lines || row_count == 0)
		return(free_string_array(lines), 0);
    temp_cols = 0;
    first_line = parse_line_to_ints(lines[0], &temp_cols);
    if (!first_line)
		return (free_string_array(lines), 0);
	i = 1;
    while (i++ < row_count)
    {
        temp_line = parse_line_to_ints(lines[i], &temp_cols);
        free(temp_line);
        if (temp_cols != *cols)
			return (free_string_array(lines), 0);
    }
    *rows = row_count;
    *cols = temp_cols;
	return (free_string_array(lines), 1);
}
