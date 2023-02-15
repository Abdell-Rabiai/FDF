/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:37:37 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/15 16:45:00 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_map *carte)
{
	carte->pline->x1 = (carte->pline->x1 - carte->pline->y1) * cos(0.8);
	carte->pline->y1 = (carte->pline->x1 + carte->pline->y1) * cos(0.8)
		- carte->z1;
	carte->pline->x2 = (carte->pline->x2 - carte->pline->y2) * cos(0.8);
	carte->pline->y2 = (carte->pline->x2 + carte->pline->y2) * cos(0.8)
		- carte->z2;
}

void	color_the_window(t_map *carte)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < carte->wid)
	{
		j = 0;
		while (++j < HEIGHT)
			my_mlx_pixel_put(&carte->image, i, j, 0x202020);
		i++;
	}
}
