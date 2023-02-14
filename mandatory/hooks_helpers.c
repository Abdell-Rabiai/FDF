/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:34:01 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 13:05:00 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation_hooks(int keycode, t_map *carte)
{
	if (keycode == 123)
		carte->translate_x -= 35;
	if (keycode == 124)
		carte->translate_x += 35;
	if (keycode == 125)
		carte->translate_y += 35;
	if (keycode == 126)
		carte->translate_y -= 35;
	if (keycode == 6)
		carte->translate_z += 35;
	if (keycode == 7)
		carte->translate_z -= 35;
}

void	scalling_hooks(int keycode, t_map *carte)
{
	if (keycode == 69)
		carte->scale += 3;
	if (keycode == 78)
		carte->scale -= 3;
	if (keycode == 8)
		carte->stretch_z += 1.1; 
	if (keycode == 9)
		carte->stretch_z -= 1.1;
}

void	colors_and_projection_hooks(int keycode, t_map *carte)
{
	if (keycode == 3)
	{
		if (carte->bool_flat == 0)
			carte->bool_flat = 1;
		else
			carte->bool_flat = 0;
	}
	if (keycode == 5)
	{
		if (carte->make_it_colorful == 0)
			carte->make_it_colorful = 1;
		else if (carte->make_it_colorful == 1)
			carte->make_it_colorful = 0;
		initialize_colors(carte);
	}
	if (keycode == 36)
	{
		if (carte->show_guid == 0)
			carte->show_guid = 1;
		else
			carte->show_guid = 0;
	}
}

void	rotation_hooks(int keycode, t_map *carte)
{
	if (keycode == 91)
		carte->rotate_x += 1;
	if (keycode == 84)
		carte->rotate_x -= 1;
	if (keycode == 86)
		carte->rotate_y += 1;
	if (keycode == 88)
		carte->rotate_y -= 1;
	if (keycode == 92)
		carte->rotate_z += 1;
	if (keycode == 83)
		carte->rotate_z -= 1;
}