/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:22:56 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/06 01:17:06 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map_with_col_val(t_map *map, char *line, int index)
{
	int		i;
	char	**tokens;
	char	**col_token;

	i = 0;
	tokens = ft_split(line, ' ');
	while (i < map->map_width)
	{
		col_token = ft_split(tokens[i], ',');//10 0xFFFF
		map->map[index][i] = ft_atoi(col_token[0]);
		map->color_map[index][i] = ft_atoi_base(col_token[1], 16);
		ft_printf("%d", map->color_map[index][i]);
		//printf("i: %d\n %d\n: ", map->map[index][i], map->color_map[index][i]);
		i++;
		free(col_token[0]);
		free(col_token[1]);
		free(col_token);
	}
	free_arr(tokens);
}
