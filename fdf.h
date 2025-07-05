/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:47:11 by lbrylins          #+#    #+#             */
/*   Updated: 2025/07/06 00:09:51 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define Z_SCALE 3
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ISO_ANGLE 0.523599
# define ZOOM 20
// # define OFFSET_X (WIN_WIDTH / 2)
// # define OFFSET_Y (WIN_HEIGHT / 4)
# define WIN_TITLE "FDF"
// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_map
{
	int				map_width;
	int				map_height;
	int				**map;
	int				**color_map;
}					t_map;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct s_line_params
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				steps;
	int				i;
}					t_line_params;

typedef struct s_line_vars
{
	int				e2;
	unsigned int	color;
	float			t;
}					t_line_vars;

typedef struct s_line_ctx
{
	t_point			a;
	t_point			b;
	unsigned int	color_a;
	unsigned int	color_b;
	t_data			*img;
}					t_line_ctx;

// prawdopodobnie niepotrzebne
typedef struct s_iso_ctx
{
	int				x;
	int				y;
	int				z;
}					t_iso_ctx;

typedef struct s_draw_ctx
{
	t_point			*end;
	t_line_params	*params;
	t_data			*img;
	unsigned int	color_a;
	unsigned int	color_b;
}					t_draw_ctx;

typedef struct s_inter_col
{
	unsigned char	a_r;
	unsigned char	a_g;
	unsigned char	a_b;
	unsigned char	b_r;
	unsigned char	b_g;
	unsigned char	b_b;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_inter_col;

size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *str, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*get_next_line(int fd);
char				*return_line(int fd, char *stash);
char				*ft_get_line(char *stash);
char				*ft_next(char *stash);
void				*ft_calloc(size_t num, size_t size);
int					ft_put_hexa_lower(unsigned long number);
int					ft_put_hexa_upper(unsigned long number);
int					ft_put_ptr(void *ptr);
int					switch_function(char *c, va_list args);
int					ft_printf(const char *str, ...);
int					ft_putchar_printf(char c);
int					ft_pustr_printf(char *str);
int					ft_putnbr_printf(int n);
int					ft_put_un_nbr_printf(unsigned int n);
int					strlen_ft(const char *str, char seperator, int start);
int					count_words(const char *str, char seperator);
char				**cleanup(char **str_arr, int word_num);
char				**ft_split(char const *s, char c);
void				free_split(char **split);
int					**read_fdf_to_matrix(const char *filename, int *rows_out,
						int *cols_out, int fd);
int					resize_matrix(int ***matrix, int *capacity);
int					handle_first_line(int fd, int **matrix, int *columns);
int					**allocate_matrix(int capacity);
int					ft_atoi(const char *str);
int					count_columns(char *line);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *src);
void				my_mlx_put_pixel(t_data *img, int x, int y, double color);
int					*parse_line_to_ints(char *line, int *width);
int					**parse_lines_to_int_array(char **lines, int row_count,
						int *cols);
int					**parse_file_to_int_array(const char *filename, int *rows,
						int *cols);
char				**read_lines_from_file(const char *filename,
						int *row_count);
void				free_string_array(char **arr);
int					get_dimensions_from_file(const char *filename, int *rows,
						int *cols);

// Parsing
int					**alloc_2d_array(int rows, int cols);
void				fill_color_row(int *color_row, int *map_row, int width);
void				fill_maps(t_map *map_data, char **lines, int if_col);
char				**read_lines(int fd, int *out_count, int cap);
t_map				*parse_map(int fd);
void				fill_row(int *row, char *line, int width);
void				free_arr(char **arr);
int					count_columns(char *line);
char				**resize_lines(char **old, int old_cap, int new_cap);
void				fill_map_with_col_val(t_map *map, char *line, int index);
void				fill_map_with_no_col_val(t_map *map, char *line, int index);
// line drawing
void				draw_line(t_point *a, t_point *b, t_data *img);
int					ft_abs(int val);
void				slope_less_then_one(int dx, int dy, t_point *a,
						t_data *img);
void				slope_bigger_than_one(int dx, int dy, t_point *a,
						t_data *img);

// window
int					handle_close(t_data *data);
int					handle_keypress(int keycode, t_data *data);
int					exit_clean(t_data *data);
void				init_window(t_data *data);
void				setup_mlx_hooks(t_data *data);

// utils
void				cleanup_and_exit(t_data *data, t_map *map, int exit_code);
void				free_map(t_map *map);
int					ft_atoi(const char *str);
char				*ft_strdup(char *src);
void				cleanup_and_exit(t_data *data, t_map *map, int exit_code);

// isometric
t_point				project_iso(t_iso_ctx c);
void				draw_line_colored(t_line_ctx ctx);
void				init_line_params(t_point *a, t_point *b, t_line_params *p);
void				draw_line_step(t_point *cur, t_draw_ctx ctx);
unsigned int		interpolate_color(unsigned int color_a,
						unsigned int color_b, float t);

// render map
t_map				*open_and_parse_map(const char *filename);
void				render_map(t_data *data, t_map *map);
void				draw_line_neighbors(t_data *data, t_map *map, int x, int y);
void				draw_down_line(t_data *data, t_map *map, int x, int y);
void				draw_right_line(t_data *data, t_map *map, int x, int y);

// atoi base
int					ft_atoi_base(const char *str, int str_base);
int					isvalid(int ch, int baselen);
int					isspace(int c);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif