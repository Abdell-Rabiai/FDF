/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/28 04:48:14 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include "../libft_utils/libft_utils.h"

typedef struct my_map
{
	int height;
	int width;
	int **matrice;
	
	void *mlx_ptr;
	void *win_ptr;
} map;

void	get_map_infos(map *carte, char *filename);
void	get_map_dimensions(char *filename, map *carte);
// int		get_map_width(char *filename);
void	fill_the_matrix(map *carte, char *filename);

int		ft_printf(const char *string_format, ...);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file_format(char *filename);

#endif