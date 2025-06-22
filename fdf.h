/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:47:11 by lbrylins          #+#    #+#             */
/*   Updated: 2025/06/16 20:35:01 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx_int.h"

#define TILE_SIZE 20
#define Z_SCALE   3
#define OFFSET_X  400
#define OFFSET_Y  200

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
	int	map_width;
	int	map_height;
	int	**map;
	int	**color_map;
}				t_map;

typedef struct s_point {
	int	x;
	int	y;
};				t_point;

typedef struct s_line_params {
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		steps;
	int		i;
}				t_line_params;

typedef struct s_line_vars {
	int				e2;
	unsigned int	color;
	float			t;
}				t_line_vars;

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
char		*return_line(int fd, char *stash);
char		*ft_get_line(char *stash);
char		*ft_next(char *stash);
void		*ft_calloc(size_t num, size_t size);
int			ft_put_hexa_lower(unsigned long number);
int			ft_put_hexa_upper(unsigned long number);
int			ft_put_ptr(void *ptr);
int			switch_function(char *c, va_list args);
int			ft_printf(const char *str, ...);
int			ft_putchar_printf(char c);
int			ft_pustr_printf(char *str);
int			ft_putnbr_printf(int n);
int			ft_put_un_nbr_printf(unsigned int n);
int			strlen_ft(const char *str, char seperator, int start);
int			count_words(const char *str, char seperator);
char		**cleanup(char **str_arr, int word_num);
char		**ft_split(char const *s, char c);
void		free_split(char **split);
int			**read_fdf_to_matrix(const char *filename, int *rows_out, int *cols_out, int fd);
int			resize_matrix(int ***matrix, int *capacity);
int			handle_first_line(int fd, int **matrix, int *columns);
int			**allocate_matrix(int capacity);
int			ft_atoi(const char *str);
int			count_columns(char *line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(char *src);
void my_mlx_put_pixel(t_data *img, int x, int y, double color);
int	*parse_line_to_ints(char *line, int *width);
int	**parse_lines_to_int_array(char **lines, int row_count, int *cols);
int	**parse_file_to_int_array(const char *filename, int *rows, int *cols);
char	**read_lines_from_file(const char *filename, int *row_count);
void	free_string_array(char **arr);
int	get_dimensions_from_file(const char *filename, int *rows, int *cols);

//Parsing
int	**alloc_2d_array(int rows, int cols);
void	fill_color_row(int *color_row, int *map_row, int width);
void	fill_maps(t_map *map_data, char **lines);
char	**read_lines(int fd, int *out_count, int cap);
t_map	*parse_map(int fd);
void	fill_row(int *row, char *line, int width);
void	free_arr(char **arr);
int	count_columns(char *line);
char	**resize_lines(char **old, int old_cap, int new_cap);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif