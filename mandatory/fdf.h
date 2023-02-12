/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/12 14:46:48 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define HEIGHT 2790/2
#define WIDTH 5120/2
#define PI 3.14159265358979323846

#include <mlx.h>
#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "../libft_utils/libft_utils.h"

typedef struct x_y_z_color
{
	int x;
	int y;
	int z;
	int color_z;
} my_matrice;

typedef struct my_map
{
	int height;
	int width;
	
	my_matrice **matrix;
	int scale;

	int translate_x;
	int translate_y;
	int translate_z;

	int rotate_x;
	int rotate_y;
	int rotate_z;

	int tz;
	int bool_flat;
	int make_it_colorful;
	int get_colors_from_map;
	
	void *mlx_ptr;
	void *win_ptr;
	
	int dx;
	int dy;
	int err;
	int step_x;
	int step_y;
	int e2;

	int z1;
	int z2;
	int color;
} map;

void display_map(map *carte); /*should be remved later*/

void initialize_colors(map *carte);

void	get_map_infos(map *carte, char *filename);
void	get_map_dimensions(char *filename, map *carte);
void	fill_the_matrix(map *carte, char *filename);

void	draw_bresenhams_line(int x1, int y1, int x2, int y2, map *carte);
void	connect_dots(map *carte);

int		ft_printf(const char *string_format, ...);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file_format(char *filename);

#endif