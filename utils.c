/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:11 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/07 17:36:37 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	plus_minus_counter;
	int	min;

	num = 0;
	min = 1;
	plus_minus_counter = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		plus_minus_counter++;
		if (*str == '-')
			min *= -1;
		str++;
	}
	if (plus_minus_counter > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (min * num);
}
char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
