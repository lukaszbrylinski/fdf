/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:52:10 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/06 01:41:09 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "fdf.h"

void	my_mlx_put_pixel(t_data *img, int x, int y, double color)
{
	int	offset;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map_data;
	int		fd;

	if (argc != 2)
		return (ft_printf("Usage: %s <map_file>\n", argv[0]), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), 1);
	map_data = parse_map(fd);
	close(fd);
	if (!map_data)
		return (ft_printf("Failed to parse map\n"), 1);
	init_window(&data);
	render_map(&data, map_data);
	free_map(map_data);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_clean, &data);
	mlx_loop(data.mlx);
	return (0);
}
