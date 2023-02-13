/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:38:28 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/13 14:06:29 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z_color(t_map *carte)
{
	int	z1;
	int	z2;

	z1 = carte->matrix[carte->pline->y1][carte->pline->x1].z;
	z2 = carte->matrix[carte->pline->y2][carte->pline->x2].z;
	if (z2 != 0 || z1 != 0)
	{
		move_the_roof(carte);
		(carte->matrix[carte->pline->y1][carte->pline->x1]).color_z = 0xff427b;
		(carte->matrix[carte->pline->y2][carte->pline->x2]).color_z = 0xff427b;
	}
	else
	{
		(carte->matrix[carte->pline->y1][carte->pline->x1]).color_z = 0x4ae2ed;
		(carte->matrix[carte->pline->y2][carte->pline->x2]).color_z = 0x4ae2ed;
	}
}

int	get_color(char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ',' || *str == '0' || *str == 'x')
		str++;
	return (ft_atohex(str));
}

void	draw_from_x_to_x1(t_map *carte, int i, int j)
{
	carte->pline->x1 = (carte->matrix[i][j]).x;
	carte->pline->y1 = (carte->matrix[i][j]).y;
	carte->pline->x2 = (carte->matrix[i][j]).x + 1;
	carte->pline->y2 = (carte->matrix[i][j]).y;
	draw_bresenhams_line(carte);
}

void	draw_from_y_to_y1(t_map *carte, int i, int j)
{
	carte->pline->x1 = (carte->matrix[i][j]).x;
	carte->pline->y1 = (carte->matrix[i][j]).y;
	carte->pline->x2 = (carte->matrix[i][j]).x;
	carte->pline->y2 = (carte->matrix[i][j]).y + 1;
	draw_bresenhams_line(carte);
}
