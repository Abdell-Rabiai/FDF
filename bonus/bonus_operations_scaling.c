/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations_scaling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:33:14 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 18:06:43 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_the_roof(t_map *carte)
{
	carte->z1 += carte->translate_z;
	carte->z2 += carte->translate_z;
}

void	scale(t_map *carte)
{
	carte->pline->x1 *= carte->scale;
	carte->pline->x2 *= carte->scale;
	carte->pline->y1 *= carte->scale;
	carte->pline->y2 *= carte->scale;
}

void	scale_z(t_map *carte)
{
	carte->z1 = carte->matrix[carte->pline->y1][carte->pline->x1].z;
	carte->z2 = carte->matrix[carte->pline->y2][carte->pline->x2].z;
	carte->z1 *= carte->stretch_z;
	carte->z2 *= carte->stretch_z;
}

void	shift_x_y(t_map *carte)
{
	carte->pline->x1 += WIDTH / 2 - (carte->width * carte->scale) / 2
		+ carte->translate_x;
	carte->pline->x2 += WIDTH / 2 - (carte->width * carte->scale) / 2
		+ carte->translate_x;
	carte->pline->y1 += HEIGHT / 2 - (carte->height * carte->scale) / 2
		+ carte->translate_y;
	carte->pline->y2 += HEIGHT / 2 - (carte->height * carte->scale) / 2
		+ carte->translate_y;
}
