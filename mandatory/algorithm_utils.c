/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:01:11 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/10 20:39:02 by arabiai          ###   ########.fr       */
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

void move_the_roof(map *carte)
{
	carte->z1  += carte->translate_z;
	carte->z2  += carte->translate_z;
}

void isometric_projection(int *x1, int *y1, int *x2, int *y2, int z1, int z2)
{
	*x1 = (*x1 - *y1) * cos(0.8);
	*y1 = (*x1 + *y1) * sin(0.8) - z1;
	*x2 = (*x2 - *y2) * cos(0.8);
	*y2 = (*x2 + *y2) * sin(0.8) - z2;
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y =  * y ; 
	* y = prev_y *  cos ( alpha )  +  ( * z )  *  sin ( alpha ) ; 
	* z =  - prev_y *  sin ( alpha )  +  ( * z )  *  cos ( alpha ) ; 
}

void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma, map *carte)
{
	int	prev_x;
	int	prev_y;

	prev_x =  *x;
	prev_y =  *y;
	if (gamma != 0)
	{
		prev_x -= (carte->width*carte->scale)/2;
		prev_y -= (carte->height*carte->scale)/2;
	}
	*x = prev_x *  cos (gamma) - prev_y * sin (gamma) ; 
	*y = prev_x *  sin (gamma) + prev_y * cos (gamma) ; 
}

void shift_x_y(int *x1, int *y1, int *x2, int *y2, map *carte)
{
	*x1 += WIDTH/2 - (carte->width*carte->scale)/2 + carte->translate_x;
	*x2 += WIDTH/2 - (carte->width*carte->scale)/2 + carte->translate_x;
	*y1 += HEIGHT/2 - (carte->height*carte->scale)/2  + carte->translate_y;
	*y2 += HEIGHT/2 - (carte->height*carte->scale)/2  + carte->translate_y;
}

void z_color(int x1, int y1, int x2, int y2, map *carte)
{
	int z1;
	int z2;

	z1 = carte->matrix[y1][x1].z;
	z2 = carte->matrix[y2][x2].z;
	if (z2 != 0 || z1 != 0)
	{
		move_the_roof(carte);
		(carte->matrix[y1][x1]).color_z = 0xff427b; // red
		(carte->matrix[y2][x2]).color_z = 0xff427b;
	}
	else
    {
		(carte->matrix[y1][x1]).color_z = 0x4ae2ed; // blue
		(carte->matrix[y2][x2]).color_z = 0x4ae2ed;
    }
}

void scale_z(map *carte, int x1, int y1, int x2, int y2)
{
	carte->z1 = carte->matrix[y1][x1].z;
	carte->z2 = carte->matrix[y2][x2].z;

	carte->z1  *= carte->tz;
	carte->z2  *= carte->tz;	
}

void initialize_bresenhams_variables(int x1, int y1, int x2, int y2, map *carte)
{	
	carte->dx = abs(x2 - x1);
	carte->dy = -abs(y2 - y1);
	carte->step_x = x1 < x2 ? 1 : -1;
	carte->step_y = y1 < y2 ? 1 : -1;
	carte->err = carte->dx + carte->dy;
}

void rotate_xyz(int *x1, int *y1, int *x2, int *y2, int *z1, int *z2, map *carte)
{
	
	rotate_x(y1, z1, M_PI / 6 * carte->rotate_x);
	rotate_x(y2, z2, M_PI / 6 * carte->rotate_x);
	rotate_y(x1, z1, M_PI / 6 * carte->rotate_y);
	rotate_y(x2, z2, M_PI / 6 * carte->rotate_y);
	rotate_z(x1, y1, M_PI / 6 * carte->rotate_z, carte);
	rotate_z(x2, y2, M_PI / 6 * carte->rotate_z, carte);

}

void draw_bresenhams_line(int x1, int y1, int x2, int y2, map *carte)
{
	int z1 = (carte->matrix[y1][x1]).z;
	int z2 = (carte->matrix[y2][x2]).z;
	scale_z(carte, x1, y1, x2, y2);
	if (carte->make_it_colorful == 0)
		z_color(x1, y1, x2, y2, carte);
	carte->color = (carte->matrix[y1][x1]).color_z;
	scale(&x1, &y1, &x2, &y2, carte);
	
	rotate_xyz(&x1, &y1, &x2, &y2, &z1, &z2, carte);
	
	if (carte->bool_flat == 1)
		isometric_projection(&x1, &y1, &x2, &y2, carte->z1, carte->z2);
	
	shift_x_y(&x1, &y1, &x2, &y2, carte);
	initialize_bresenhams_variables(x1, y1, x2, y2, carte);
	while (1)
	{
		mlx_pixel_put(carte->mlx_ptr, carte->win_ptr, x1, y1, carte->color);
		if (x1 == x2 && y1 == y2)
			break;
		carte->e2 = 2 * carte->err;
		if (carte->e2 >= carte->dy)
		{
			carte->err = carte->err + carte->dy;
			x1 = x1 + carte->step_x;
		}
		else if (carte->e2 <= carte->dx)
		{
			carte->err = carte->err + carte->dx;
			y1 = y1 + carte->step_y;
		}
	}
}

void connect_dots(map *carte)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < carte->height)
	{
		j = 0;
		while (j < carte->width)
		{
			if ( j < carte->width - 1)
				draw_bresenhams_line((carte->matrix[i][j]).x, (carte->matrix[i][j]).y, (carte->matrix[i][j]).x + 1, (carte->matrix[i][j]).y, carte);
			if ( i < carte->height - 1)
                draw_bresenhams_line((carte->matrix[i][j]).x, (carte->matrix[i][j]).y, (carte->matrix[i][j]).x, (carte->matrix[i][j]).y + 1, carte);
			j++;
		}
		i++;
	}
}