/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:58:03 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/06 19:58:23 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

// int	ft_pustr_printf(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

int	ft_pustr_printf(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		write(1, str, 1);
		i++;
		str++;
	}
	return (i);
}

int	ft_putnbr_printf(int n)
{
	int		num;

	num = 0;
	if (n == -2147483648)
	{
		num += write(1, "-2147483648", 11);
		return (num);
	}
	if (n < 0)
	{
		num += write(1, "-", 1);
		n *= -1;
		num += ft_putnbr_printf(n);
	}
	else if (n > 9)
	{
		num += ft_putnbr_printf(n / 10);
		num += ft_putnbr_printf(n % 10);
	}
	else if (n <= 9)
		num += ft_putchar_printf(n + 48);
	return (num);
}

int	ft_put_un_nbr_printf(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_put_un_nbr_printf(n / 10);
		count += ft_put_un_nbr_printf(n % 10);
	}
	else if (n <= 9)
		count += write(1, &((char []){n + '0'}), 1);
	return (count);
}