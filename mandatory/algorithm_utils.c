/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:01:11 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 17:24:10 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_bresenhams_variables(t_map *carte)
{
	carte->dx = abs(carte->pline->x2 - carte->pline->x1);
	carte->dy = -abs(carte->pline->y2 - carte->pline->y1);
	if (carte->pline->x1 < carte->pline->x2)
		carte->step_x = 1;
	else
		carte->step_x = -1;
	if (carte->pline->y1 < carte->pline->y2)
		carte->step_y = 1;
	else
		carte->step_y = -1;
	carte->err = carte->dx + carte->dy;
}

void	all_the_stuff_before_bresenhams(t_map *carte)
{
	int	z1;
	int	z2;

	z1 = (carte->matrix[carte->pline->y1][carte->pline->x1]).z;
	z2 = (carte->matrix[carte->pline->y2][carte->pline->x2]).z;
	scale_z(carte);
	if (carte->make_it_colorful == 0)
		z_color(carte);
	carte->color = (carte->matrix[carte->pline->y1][carte->pline->x1]).color_z;
	scale(carte);
	rotate_xyz(&z1, &z2, carte);
	if (carte->bool_flat == 1)
		isometric_projection(carte);
	shift_x_y(carte);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_bresenhams_line(t_map *carte)
{
	all_the_stuff_before_bresenhams(carte);
	initialize_bresenhams_variables(carte);
	while (1)
	{
		if ((carte->pline->x1 > 0 && carte->pline->x1 < WIDTH)
			&& (carte->pline->y1 > 0 && carte->pline->y1 < HEIGHT))
			my_mlx_pixel_put(&carte->image, carte->pline->x1, carte->pline->y1,
				create_argb(0, (carte->color >> 16), (carte->color >> 8)
					+ carte->z1, carte->color - carte->z1 / 2));
		if (carte->pline->x1 == carte->pline->x2
			&& carte->pline->y1 == carte->pline->y2)
			break ;
		carte->e2 = 2 * carte->err;
		if (carte->e2 >= carte->dy)
		{
			carte->err = carte->err + carte->dy;
			carte->pline->x1 = carte->pline->x1 + carte->step_x;
		}
		else if (carte->e2 <= carte->dx)
		{
			carte->err = carte->err + carte->dx;
			carte->pline->y1 = carte->pline->y1 + carte->step_y;
		}
	}
}

void	connect_dots(t_map *carte)
{
	int	i;
	int	j;

	i = 0;
	if (carte->show_guid == 1)
		put_strings(carte);
	while (i < carte->height)
	{
		j = 0;
		while (j < carte->width)
		{
			if (j < carte->width - 1)
				draw_from_x_to_x1(carte, i, j);
			if (i < carte->height - 1)
				draw_from_y_to_y1(carte, i, j);
			j++;
		}
		i++;
	}
}
