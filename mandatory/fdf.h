/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 16:19:28 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1400
# define WIDTH 2600
# define PI 3.14159265358979323846

# include <mlx.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft_utils/libft_utils.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
typedef struct x_y_z_color
{
	int	x;
	int	y;
	int	z;
	int	color_z;
}	t_matrice;

typedef struct s_point
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_point;

typedef struct my_map
{
	int			height;
	int			width;
	t_matrice	**matrix;
	t_point		*pline;
	t_data		image;
	void		*mlx_ptr;
	void		*win_ptr;
	int			scale;
	int			translate_x;
	int			translate_y;
	int			translate_z;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
	double		stretch_z;
	int			bool_flat;
	int			show_guid;
	int			make_it_colorful;
	int			get_colors_from_map;
	int			dx;
	int			dy;
	int			err;
	int			step_x;
	int			step_y;
	int			e2;
	int			z1;
	int			z2;
	int			color;
}	t_map;

// void	display_map(map *carte); /*should be remved later*/

void	get_map_infos(t_map *carte, char *filename);
void	get_map_dimensions(char *filename, t_map *carte);
void	fill_the_matrix(t_map *carte, char *filename);
// void	draw_bresenhams_line(int x1, int y1, int x2, int y2, t_map *carte);
void	draw_bresenhams_line(t_map *carte);
void	connect_dots(t_map *carte);
/*bonus operations rotation*/
void	rotate_xyz(int *z1, int *z2, t_map *carte);
void	rotate_z(int *x, int *y, double gamma, t_map *carte);
void	rotate_y(int *x, int *z, double beta);
void	rotate_x(int *y, int *z, double alpha);
/*bonus operations scaling*/
void	scale(t_map *carte);
void	scale_z(t_map *carte);
void	move_the_roof(t_map *carte);
void	shift_x_y(t_map *carte);
/*projectino utils*/
void	isometric_projection(t_map *carte);
/*colors*/
int		get_color(char *str);
void	z_color(t_map *carte);
int		create_argb(int a, int r, int g, int b);
/*helper functions for bresnhems line*/
void	draw_from_x_to_x1(t_map *carte, int i, int j);
void	draw_from_y_to_y1(t_map *carte, int i, int j);
/*init().c*/
void	initialize_bres_bonus_ops(t_map *carte);
void	initialize_map(t_map *carte);
void	initialize_matrix(t_map *carte);
void	initialize_colors(t_map *carte);
/*hoooks helpers*/
void	translation_hooks(int keycode, t_map *carte);
void	scalling_hooks(int keycode, t_map *carte);
void	colors_and_projection_hooks(int keycode, t_map *carte);
void	rotation_hooks(int keycode, t_map *carte);
/**strings guide*/
void	put_strings(t_map *carte);

int		ft_printf(const char *string_format, ...);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file_format(char *filename);

#endif