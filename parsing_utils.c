/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:18:23 by marvin            #+#    #+#             */
/*   Updated: 2025/06/29 14:18:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_row(int *row, char *line, int width)
{
	int		i;
	char	**tokens;

	i = 0;
	tokens = ft_split(line, ' ');
	while (i < width)
	{
		row[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_arr(tokens);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
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
