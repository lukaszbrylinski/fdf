/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:52:10 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/16 20:40:01 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx-linux/mlx.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

void my_mlx_put_pixel(t_data *img, int x, int y, double color)
{
	int		offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int *rows, *cols;
	int		**input_array;

	mlx = NULL;
	rows = NULL;
	cols = NULL;
	if (argc == 2)
	{
		if (get_dimensions_from_file(argv[1], rows, cols))
		{
			input_array = parse_file_to_int_array(argv[1], rows, cols);
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
		}
		img = mlx_new_image(mlx, 1920, 1080);
		mlx_loop(mlx);
	}
	return (0);
}
