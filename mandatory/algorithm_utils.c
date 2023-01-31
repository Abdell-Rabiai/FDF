/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:01:11 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/31 22:31:34 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void scale(int *x1, int *y1, int *x2, int *y2, map *carte)
{
	*x1 = *x1 * carte->scale;
	*x2 = *x2 * carte->scale;
	*y1 = *y1 * carte->scale;
	*y2 = *y2 * carte->scale;
}

int z_color(int x1, int y1, int x2, int y2, map *carte)
{
	int z1;
	int z2;

	z1 = carte->matrice[y1][x1];
	z2 = carte->matrice[y2][x2];
	if (z1 != 0 || z2 != 0)
		return (0xff427b);
	else
		return (0x4ae2ed);
}

void isometric_projection(int *x1, int *y1, int *x2, int *y2, int z1, int z2)
{
	// x` = (x - y) * cos(angle)
	// y` = (x + y) * sin(angle) - z
	// - x` and y` are coordintes in 3D format (default angle 0.8)
	*x1 = (*x1 - *y1) * cos(0.52);
	*y1 = (*x1 + *y1) * sin(0.52) - z1;
	*x2 = (*x2 - *y2) * cos(0.52);
	*y2 = (*x2 + *y2) * sin(0.52) - z2;
}

void shift_x_y(int *x1, int *y1, int *x2, int *y2, map *carte)
{
	*x1 = *x1 + WIDTH/4 + carte->translate_x;
	*x2 = *x2 + WIDTH/4 + carte->translate_x; 
	*y1 = *y1 + HEIGHT/3 + carte->translate_y;
	*y2 = *y2 + HEIGHT/3 + carte->translate_y;
}

void draw_bresenhams_line(int x1, int y1, int x2, int y2, map *carte)
{
	printf("HELLO 78\n");
	carte->bres->z1 = carte->matrice[y1][x1];
	carte->bres->z2 = carte->matrice[y2][x2];
	carte->bres->color_z = z_color(x1, y1, x2, y2, carte);
	
	scale(&x1, &y1, &x2, &y2, carte);
	isometric_projection(&x1, &y1, &x2, &y2, carte->bres->z1, carte->bres->z2);
	shift_x_y(&x1, &y1, &x2, &y2, carte);
	
	carte->bres->dx = abs(x2 - x1);
	carte->bres->dy = -abs(y2 - y1);
	carte->bres->step_x = x1 < x2 ? 1 : -1;
	carte->bres->step_y = y1 < y2 ? 1 : -1;
	carte->bres->err = carte->bres->dx + carte->bres->dy;
	while (1)
	{
		mlx_pixel_put(carte->mlx_ptr, carte->win_ptr, x1, y1, carte->bres->color_z);
		if (x1 == x2 && y1 == y2)
			break;
		carte->bres->e2 = 2 * carte->bres->err;
		if (carte->bres->e2 >= carte->bres->dy)
		{
			carte->bres->err = carte->bres->err + carte->bres->dy;
			x1 = x1 + carte->bres->step_x;
		}
		else if (carte->bres->e2 <= carte->bres->dx)
		{
			carte->bres->err = carte->bres->err + carte->bres->dx;
			y1 = y1 + carte->bres->step_y;
		}
	}
}

void connect_dots(map *carte)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < carte->height)
	{
		x = 0;
		while (x < carte->width)
		{
			if ( x < carte->width - 1)
				draw_bresenhams_line(x, y, x + 1, y, carte);
			if ( y < carte->height - 1)
				draw_bresenhams_line(x, y, x, y + 1, carte);
			x++;
		}
		y++;
	}
}