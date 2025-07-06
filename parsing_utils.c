/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:18:23 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 03:48:41 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	fill_row(int *row, char *line, int width)
// {
// 	int		i;
// 	char	**tokens;

// 	i = 0;
// 	tokens = ft_split(line, ' ');
// 	while (i < width)
// 	{
// 		row[i] = ft_atoi(tokens[i]);
// 		i++;
// 	}
// 	free_arr(tokens);
// }

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	count_columns(char *line)
{
	int		count;
	char	**tokens;

	count = 0;
	tokens = ft_split(line, ' ');
	while (tokens[count])
		count++;
	free_arr(tokens);
	return (count);
}

char	**resize_lines(char **old, int old_cap, int new_cap)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * new_cap);
	if (!new)
		return (NULL);
	while (i < old_cap)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

void	fill_map_with_col_val(t_map *map, char **line)
{
	int		i;
	int		j;
	char	**tokens;
	char	**col_token;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		tokens = ft_split(line[i], ' ');
		while (j < map->map_width)
		{
			col_token = ft_split(tokens[j], ',');
			map->map[i][j] = ft_atoi(col_token[0]);
			map->color_map[i][j] = ft_atoi_base(col_token[1], 16);
			j++;
			free_arr(col_token);
		}
		free_arr(tokens);
		i++;
	}
}
