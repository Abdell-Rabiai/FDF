/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:37:37 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/16 17:29:15 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//PI / 6 = 0.52
void	isometric_projection_octant3(t_map *carte)
{
	carte->pline->x1 = (carte->pline->x1) * cos(PI / 6)
		- (carte->z1) * sin(PI / 6);
	carte->pline->y1 = (carte->pline->y1) - carte->z1;
	carte->pline->x2 = (carte->pline->x2) * cos(PI / 6)
		- (carte->z2) * sin(PI / 6);
	carte->pline->y2 = (carte->pline->y2) - carte->z2;
}

void	isometric_projection_octant2(t_map *carte)
{
	carte->pline->x1 = (carte->pline->x1);
	carte->pline->y1 = (carte->pline->y1) * cos(35.264)
		+ carte->z1 * sin(35.264);
	carte->pline->x2 = (carte->pline->x2);
	carte->pline->y2 = (carte->pline->y2) * cos(35.264)
		+ carte->z2 * sin(35.264);
}

void	isometric_projection_octant1(t_map *carte)
{
	carte->pline->x1 = (carte->pline->x1 - carte->pline->y1) * cos(PI / 6);
	carte->pline->y1 = (carte->pline->x1 + carte->pline->y1) * cos(PI / 6)
		- carte->z1;
	carte->pline->x2 = (carte->pline->x2 - carte->pline->y2) * cos(PI / 6);
	carte->pline->y2 = (carte->pline->x2 + carte->pline->y2) * cos(PI / 6)
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
