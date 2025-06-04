/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:52:10 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/04 22:40:49 by lbrylins         ###   ########.fr       */
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

static void my_mlx_put_pixel(t_data *img, int x, int y, double color)
{
	int		offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}
//******************************************* */
// DO POPRAWY funkcja zliczajaca ile jest wierszy
int	get_row_num(int fd)
{
	char	*buf;
	char	*temp;
	ssize_t	bytes_read;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), NULL);
		buf[bytes_read] = '\0';
		if (!stash)
			stash = ft_calloc(1, 1);
		temp = stash;
		stash = ft_strjoin(stash, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}
char	**read_file_into_array(const char *filename)
{
	int		fd;
	char	*line;
	char	**lines = NULL;
	int		capacity = 10;
	int		count = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Failed to open file"), NULL);
	lines = malloc(sizeof(char *) * capacity);
	if (!lines)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (count >= capacity)
		{
			capacity *= 2;
			char **new_lines = realloc(lines, sizeof(char *) * capacity);
			if (!new_lines)
			{
				for (int i = 0; i < count; i++)
					free(lines[i]);
				free(lines);
				close(fd);
				return (NULL);
			}
			lines = new_lines;
		}
		lines[count++] = line;
	}
	lines = realloc(lines, sizeof(char *) * (count + 1));
	lines[count] = NULL;
	close(fd);
	return lines;
}
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*map;

	if (argc == 2)
	{
		map = get_next_line(argv[1]);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1000, 1000, "FDF");
		img.img = mlx_new_image(mlx, 1000, 1000);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		my_mlx_put_pixel(&img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
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
