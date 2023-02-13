/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_everything.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:24:59 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/13 16:42:10 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_bres_bonus_ops(t_map *carte)
{
	carte->dx = 0;
	carte->dy = 0;
	carte->err = 0;
	carte->step_x = 0;
	carte->step_y = 0;
	carte->e2 = 0;
	carte->translate_x = 0;
	carte->translate_y = 0;
	carte->translate_z = 0;
	carte->rotate_x = 0;
	carte->rotate_y = 0;
	carte->rotate_z = 0;
	carte->bool_flat = 1;
	carte->show_guid = 1;
	carte->stretch_z = 1;
}

void	initialize_map(t_map *carte)
{
	carte->height = 0;
	carte->width = 0;
	carte->matrix = NULL;
	carte->pline = (t_point *)malloc(sizeof(t_point));
	carte->pline->x1 = 0;
	carte->pline->x2 = 0;
	carte->pline->y1 = 0;
	carte->pline->y2 = 0;
	carte->scale = 8;
	carte->make_it_colorful = 1;
	carte->get_colors_from_map = 1;
	carte->mlx_ptr = mlx_init();
	carte->win_ptr = mlx_new_window(carte->mlx_ptr, WIDTH,
			HEIGHT, "fill de fer");
	carte->z1 = 0;
	carte->z2 = 0;
	initialize_bres_bonus_ops(carte);
}

void	initialize_matrix(t_map *carte)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < carte->height)
	{
		j = 0;
		while (j < carte->width)
		{
			(carte->matrix[i][j]).x = 0;
			(carte->matrix[i][j]).y = 0;
			(carte->matrix[i][j]).z = 0;
			(carte->matrix[i][j]).color_z = 0xffffff;
			j++;
		}
		i++;
	}
}

void	initialize_colors(t_map *carte)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < carte->height)
	{
		j = 0;
		while (j < carte->width)
		{
			(carte->matrix[i][j]).color_z = 0xffffff;
			j++;
		}
		i++;
	}
}