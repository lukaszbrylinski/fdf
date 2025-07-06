/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:01:52 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 03:43:04 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_iso(t_iso_ctx ctx)
{
	t_point	pt;

	pt.x = (ctx.x - ctx.y) * cos(ISO_ANGLE) * ZOOM + WIN_WIDTH / 2;
	pt.y = (ctx.x + ctx.y) * sin(ISO_ANGLE) * ZOOM - ctx.z * 10 + WIN_HEIGHT
		/ 4;
	return (pt);
}

void	draw_line_colored(t_line_ctx ctx)
{
	t_line_params	p;
	t_point			cur;
	t_draw_ctx		draw_ctx;

	init_line_params(&ctx.a, &ctx.b, &p);
	cur = ctx.a;
	draw_ctx = (t_draw_ctx){.end = &ctx.b, .params = &p, .img = ctx.img,
		.color_a = ctx.color_a, .color_b = ctx.color_b};
	draw_line_step(&cur, draw_ctx);
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

void	draw_line_step(t_point *cur, t_draw_ctx ctx)
{
	t_line_vars	v;

	while (ctx.params->i <= ctx.params->steps)
	{
		if (ctx.params->steps == 0)
			v.t = 0.0f;
		else
			v.t = (float)ctx.params->i / (float)ctx.params->steps;
		v.color = interpolate_color(ctx.color_a, ctx.color_b, v.t);
		my_mlx_put_pixel(ctx.img, cur->x, cur->y, v.color);
		if (cur->x == ctx.end->x && cur->y == ctx.end->y)
			break ;
		v.e2 = 2 * ctx.params->err;
		if (v.e2 > -ctx.params->dy)
		{
			ctx.params->err -= ctx.params->dy;
			cur->x += ctx.params->sx;
		}
		if (v.e2 < ctx.params->dx)
		{
			ctx.params->err += ctx.params->dx;
			cur->y += ctx.params->sy;
		}
		ctx.params->i++;
	}
}

unsigned int	interpolate_color(unsigned int color_a, unsigned int color_b,
		float t)
{
	t_inter_col	col;

	col.a_r = (color_a >> 16) & 0xFF;
	col.a_g = (color_a >> 8) & 0xFF;
	col.a_b = color_a & 0xFF;
	col.b_r = (color_b >> 16) & 0xFF;
	col.b_g = (color_b >> 8) & 0xFF;
	col.b_b = color_b & 0xFF;
	col.r = (1 - t) * col.a_r + t * col.b_r;
	col.g = (1 - t) * col.a_g + t * col.b_g;
	col.b = (1 - t) * col.a_b + t * col.b_b;
	return ((col.r << 16) | (col.g << 8) | col.b);
}
