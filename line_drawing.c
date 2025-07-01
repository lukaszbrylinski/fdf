/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:44 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/01 21:31:26 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_point *a, t_point *b, t_data *img)
{
	int	dx;
	int	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	//my_mlx_pixel_put(img, a->x,a->y, 0xFFFFFF);
	if (ft_abs(dx) > ft_abs(dy))
		slope_less_then_one(dx, dy, a, img);
	else
		slope_bigger_than_one(dx, dy, a, img);
}

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}

void slope_less_then_one(int dx, int dy, t_point *a, t_data *img)
{
	int p;
	int i;

	i = 0;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	my_mlx_put_pixel(img, a->x,a->y, 0xFFFFFF);
	while (++i < abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * ft_abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
		my_mlx_put_pixel(img, a->x,a->y, 0xFFFFFF);
	}
}

void slope_bigger_than_one(int dx, int dy, t_point *a, t_data *img)
{
	int p;
	int i;

	i = 0;
	p = 2 * dx - dy;
	my_mlx_put_pixel(img, a->x,a->y, 0xFFFFFF);
	while (++i < ft_abs(dy))
	{
		if (dy > 0)
			a->y += 1;
		else
			a->y -= 1;
		if (p < 0)
			p = p + 2 * ft_abs(dx);
		else
		{
			if (dx > 0)
				a->x += 1;
			else
				a->x -= 1;
			p = p + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
		my_mlx_put_pixel(img, a->x,a->y, 0xFFFFFF);
	}
}
