/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrylins <lbrylins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:47:11 by lbrylins          #+#    #+#             */
/*   Updated: 2025/05/07 20:26:39 by lbrylins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*return_line(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_next(char *stash);
void	*ft_calloc(size_t num, size_t size);
int		ft_put_hexa_lower(unsigned long number);
int		ft_put_hexa_upper(unsigned long number);
int		ft_put_ptr(void *ptr);
int		switch_function(char *c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_putchar_printf(char c);
int		ft_pustr_printf(char *str);
int		ft_putnbr_printf(int n);
int		ft_put_un_nbr_printf(unsigned int n);
int		strlen_ft(const char *str, char seperator, int start);
int		count_words(const char *str, char seperator);
char	**cleanup(char **str_arr, int word_num);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
int		**read_fdf_to_matrix(const char *filename, int *rows_out, int *cols_out, int fd);
int		resize_matrix(int ***matrix, int *capacity);
int		handle_first_line(int fd, int **matrix, int *columns);
int		**allocate_matrix(int capacity);
int		*parse_line_to_ints(char *line, int columns);
int		ft_atoi(const char *str);
int		count_columns(char *line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif