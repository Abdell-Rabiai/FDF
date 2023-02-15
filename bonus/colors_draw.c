/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:38:28 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 18:07:08 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
