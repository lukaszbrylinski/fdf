/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:59:18 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/06 19:59:43 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_put_hexa_lower(unsigned long num)
{
	char	*base;
	char	buffer[16];
	int		i;
	int		count;

	count = 0;
	i = 0;
	base = "0123456789abcdef";
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = base[num % 16];
			num /= 16;
		}
	}
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	ft_put_hexa_upper(unsigned long num)
{
	char	*base;
	char	buffer[8];
	int		i;
	int		count;

	count = 0;
	i = 0;
	base = "0123456789ABCDEF";
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = base[num % 16];
			num /= 16;
		}
	}
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long) ptr;
	if (ptr == NULL)
		count += write (1, "(nil)", 5);
	else if (addr == 0)
		return (count + write(1, "0x0", 3));
	else
	{
		count += write(1, "0x", 2);
		count += ft_put_hexa_lower(addr);
	}
	return (count);
}

int	switch_function(char *c, va_list args)
{
	int	count;

	count = 0;
	if (*c == 'c')
		count += ft_putchar_printf(va_arg(args, int));
	else if (*c == 's')
		count += ft_pustr_printf(va_arg(args, char *));
	else if (*c == 'p')
		count += ft_put_ptr(va_arg(args, void *));
	else if (*c == 'd' || *c == 'i')
		count += ft_putnbr_printf(va_arg(args, int));
	else if (*c == 'u')
		count += ft_put_un_nbr_printf(va_arg(args, unsigned int));
	else if (*c == 'x')
		count += ft_put_hexa_lower(va_arg(args, unsigned int));
	else if (*c == 'X')
		count += ft_put_hexa_upper(va_arg(args, unsigned int));
	else if (*c == '%')
		count += ft_putchar_printf('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += switch_function((char *)++str, args);
		else
		{
			count += write(1, str, 1);
		}
		++str;
	}
	va_end(args);
	return (count);
}
