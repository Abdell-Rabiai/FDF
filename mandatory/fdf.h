/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/31 22:25:15 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define HEIGHT 1000
#define WIDTH 1500

#include <mlx.h>
#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "../libft_utils/libft_utils.h"
typedef struct bresenham
{
	int dx;
	int dy;
	int err;
	int step_x;
	int step_y;
	int e2;

	int z1;
	int z2;
	int color_z;
} bresenham;

typedef struct my_map
{
	int height;
	int width;
	
	int **matrice;
	int scale;

	int translate_x;
	int translate_y;
	int translate_z;
	
	void *mlx_ptr;
	void *win_ptr;
	bresenham *bres;
} map;


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