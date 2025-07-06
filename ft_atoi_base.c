/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:48:56 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/06 03:52:22 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;
	int	i;

	i = 2;
	res = 0;
	sign = 1;
	while (isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] && isvalid(str[i], str_base))
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= 9)
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (res * sign);
}

int	isvalid(int ch, int baselen)
{
	char	*lcbase;
	char	*ucbase;
	int		i;

	lcbase = "0123456789abcdef";
	ucbase = "0123456789ABCDEF";
	i = 0;
	while (i < baselen)
	{
		if (ch == lcbase[i] || ch == ucbase[i])
			return (1);
		i++;
	}
	return (0);
}

int	isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}
