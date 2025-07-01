/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:52:10 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/01 22:31:27 by lbrylins         ###   ########.fr       */
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

// static void	clean_and_write_msg(t_map *map, char *msg)
// {
// 		if (msg)
// 		ft_printf("%s\n", msg);
// 	if (map)
// 	{
// 		free_map(map);
// 		free(map);
// 	}
// 	exit(1);
// }
int main(int argc, char **argv)
{
    t_data data;
    t_map *map_data;
    int fd;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    map_data = parse_map(fd);
    close(fd);
    if (!map_data)
    {
        ft_printf("Failed to parse map\n");
        return (1);
    }
    init_window(&data);
    render_map(&data, map_data);
    mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
    mlx_hook(data.win, 17, 1L << 17, exit_clean, &data);
    mlx_loop(data.mlx);
	free_map(map_data);
    return (0);
}



