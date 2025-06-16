/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:44 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/15 16:34:18 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresenham(int x1, int y1, int x2, int y2, t_data *img)
{
	int	m_new;
	int	slope_error_new;
	int	x;
	int	y;

	y = y1;
	x = x1;
	m_new = 2 * (y2 - y1);
	slope_error_new = m_new - (x2 - x1);
	while (x <= x2)
	{
		my_mlx_put_pixel(img, x, y, 0x00FF0000);
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2* (x2 - x1);
		}
	}
}
