/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:01:52 by marvin            #+#    #+#             */
/*   Updated: 2025/06/22 23:01:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_iso(int x, int y, int z)
{
	t_point	p;

	p.x = (x - y) * cos(0.523599) * TILE_SIZE + OFFSET_X;
	p.y = (x + y) * sin(0.523599) * TILE_SIZE - z * Z_SCALE + OFFSET_Y;
	return (p);
}

void	draw_line_colored(t_point *a, t_point *b, t_data *img, unsigned int color_a, unsigned int color_b)
{
	t_line_params	p;
	t_point			cur;

	init_line_params(a, b, &p);
	cur = *a;
	draw_line_step(&cur, b, &p, img, color_a, color_b);
}

void	init_line_params(t_point *a, t_point *b, t_line_params *p)
{
	p->dx = ft_abs(b->x - a->x);
	p->dy = ft_abs(b->y - a->y);
	if (b->x >= a->x)
		p->sx = 1;
	else
		p->sx = -1;
	if (b->y >= a->y)
		p->sy = 1;
	else
		p->sy = -1;
	p->err = p->dx - p->dy;
	p->steps = p->dx;
	if (p->dy > p->dx)
		p->steps = p->dy;
	p->i = 0;
}
void	draw_line_step(t_point *cur, t_point *b, t_line_params *p,
						t_data *img, unsigned int color_a, unsigned int color_b)
{
	t_line_vars	v;

	while (p->i <= p->steps)
	{
		if (p->steps == 0)
			v.t = 0.0f;
		else
			v.t = (float)p->i / (float)p->steps;
		v.color = interpolate_color(color_a, color_b, v.t);
		my_mlx_pixel_put(img, cur->x, cur->y, v.color);
		if (cur->x == b->x && cur->y == b->y)
			break;
		v.e2 = 2 * p->err;
		if (v.e2 > -p->dy)
		{
			p->err -= p->dy;
			cur->x += p->sx;
		}
		if (v.e2 < p->dx)
        {
			p->err += p->dx;
			cur->y += p->sy;
		}
		p->i++;
	}
}

unsigned int	interpolate_color(unsigned int color_a, unsigned int color_b, float t)
{
	unsigned char	a_r = (color_a >> 16) & 0xFF;
	unsigned char	a_g = (color_a >> 8) & 0xFF;
	unsigned char	a_b = color_a & 0xFF;
	unsigned char	b_r = (color_b >> 16) & 0xFF;
	unsigned char	b_g = (color_b >> 8) & 0xFF;
	unsigned char	b_b = color_b & 0xFF;
	unsigned int	r = (1 - t) * a_r + t * b_r;
	unsigned int	g = (1 - t) * a_g + t * b_g;
	unsigned int	b = (1 - t) * a_b + t * b_b;
	return ((r << 16) | (g << 8) | b);
}
