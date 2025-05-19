/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:52:10 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/19 22:13:17 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

static void my_mlx_put_pixel(t_data *img, int x, int y, double color)
{
	int		offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_put_pixel(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
// int main(void)
// {
// 	void	*mlx;
// 	//void	*mlx_win;
// 	void	*img;
// 	//int rows, cols;
// 	//int **matrix = read_fdf_to_matrix("42.fdf", &rows, &cols, 0);

// 	mlx = mlx_init();
// 	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
// 	img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_loop(mlx);
// 	// for (int i = 0; i < rows; i++)
// 	// {
// 	// 	for (int j = 0; j < cols; j++)
// 	// 		ft_printf("%d ", matrix[i][j]);
// 	// 	ft_printf("\n");
// 	// 	free(matrix[i]);
// 	// }
// 	// free(matrix);
// 	// return (0);
// }
