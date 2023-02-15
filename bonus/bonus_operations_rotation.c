/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:30:12 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 19:47:03 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(int *y, int *z, double alpha, t_map *carte)
{
	int	prev_y;

	prev_y = *y;
	if (alpha != 0)
		prev_y -= (carte->height * carte->scale) / 2;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta, t_map *carte)
{
	int	prev_x;

	prev_x = *x;
	if (beta != 0)
		prev_x -= (carte->width * carte->scale) / 2;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma, t_map *carte)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	if (gamma != 0)
	{
		prev_x -= (carte->width * carte->scale) / 2;
		prev_y -= (carte->height * carte->scale) / 2;
	}
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	rotate_xyz(int *z1, int *z2, t_map *carte)
{
	rotate_x(&carte->pline->y1, z1, PI / 6 * carte->rotate_x, carte);
	rotate_x(&carte->pline->y2, z2, PI / 6 * carte->rotate_x, carte);
	rotate_y(&carte->pline->x1, z1, PI / 6 * carte->rotate_y, carte);
	rotate_y(&carte->pline->x2, z2, PI / 6 * carte->rotate_y, carte);
	rotate_z(&carte->pline->x1, &carte->pline->y1, PI / 6 * carte->rotate_z,
		carte);
	rotate_z(&carte->pline->x2, &carte->pline->y2, PI / 6 * carte->rotate_z,
		carte);
}
