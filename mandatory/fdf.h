/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/16 17:28:11 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../bonus/fdf_bonus.h"

// void	display_map(map *carte); /*should be remved later*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	color_the_window(t_map *carte);

void	get_map_infos(t_map *carte, char *filename);
void	get_map_dimensions(char *filename, t_map *carte);
void	fill_the_matrix(t_map *carte, char *filename);
// void	draw_bresenhams_line(int x1, int y1, int x2, int y2, t_map *carte);
void	draw_bresenhams_line(t_map *carte);
void	connect_dots(t_map *carte);

/*projectino utils*/
void	isometric_projection_octant1(t_map *carte);
void	isometric_projection_octant2(t_map *carte);
void	isometric_projection_octant3(t_map *carte);

/*helper functions for bresnhems line*/
void	draw_from_x_to_x1(t_map *carte, int i, int j);
void	draw_from_y_to_y1(t_map *carte, int i, int j);
/*init().c*/
void	initialize_bres_bonus_ops(t_map *carte);
void	initialize_map(t_map *carte);
void	initialize_matrix(t_map *carte);
void	reset_to_the_initial_state(t_map *carte);
/**strings guide*/
void	put_strings(t_map *carte);

int		ft_printf(const char *string_format, ...);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file_format(char *filename);

#endif