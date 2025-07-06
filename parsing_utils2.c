/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:45:40 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/06 03:46:26 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_min_value_to_map(t_map *map, int min)
{
	int	i;
	int	j;

	i = 0;
	if (min < 0)
	{
		while (i < map->map_height)
		{
			j = 0;
			while (j < map->map_width)
			{
				map->map[i][j] += -min;
				j++;
			}
			i++;
		}
	}
}

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
