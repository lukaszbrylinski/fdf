/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:44 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/07 21:00:08 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresenham(int x1, int y1, int x2, int y2)
{
	int	m_new;
	int	slope_error_new;

	m_new = 2 * (y2 - y1);
	slope_error_new = m_new - (x2 - x1);
	while (x1 < x2)
	{
		
		slope_error_new += m_new;
	}
}