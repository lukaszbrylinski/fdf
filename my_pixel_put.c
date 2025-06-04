/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:17:09 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/04 20:41:21 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_pixel_img(int x, int y, s_win *win, int color)
{
  int	pix;

  if (x < 0 || y < 0 || x > win->w || y > win->h)
    return (-1);
  pix = x * 4 + win->d_img.szl * y;
  (win->d_img.data)[pix] = color;
  (win->d_img.data)[pix + 1] = color >> 8;
  (win->d_img.data)[pix + 2] = color >> 16;
  return (0);
}