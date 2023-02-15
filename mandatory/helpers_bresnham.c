/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bresnham.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:59:35 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 17:59:57 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

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
