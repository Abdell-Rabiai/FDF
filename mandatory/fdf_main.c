/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:53 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/12 14:44:30 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void initialize_map(map *carte)
{
	carte->height = 0;
	carte->width = 0;
	
	carte->matrix = NULL;
	carte->scale = 8;

	carte->translate_x = 0;
	carte->translate_y = 0;
	carte->translate_z = 0;

	carte->rotate_x = 0;
	carte->rotate_y = 0;
	carte->rotate_z = 0;

	carte->tz = 1;
	carte->bool_flat = 1;
	carte->make_it_colorful = 1;
	carte->get_colors_from_map = 1;
	
	carte->mlx_ptr = mlx_init();
	carte->win_ptr = mlx_new_window(carte->mlx_ptr, WIDTH, HEIGHT, "fill de fer");
	
	carte->dx = 0;
	carte->dy = 0;
	carte->err = 0;
	carte->step_x = 0;
	carte->step_y = 0;
	carte->e2 = 0;

	carte->z1 = 0;
	carte->z2 = 0;
}

void initialize_matrix(map *carte)
{
	int i;
	int j;

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

void initialize_colors(map *carte)
{
	int i;
	int j;

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

void translation(int keycode, map *carte)
{
	printf("%d\n", keycode);
	if (keycode == 123) // left
		carte->translate_x -= 35;
	if (keycode == 124) //right
		carte->translate_x += 35;
	if (keycode == 125) // down
		carte->translate_y += 35;
	if (keycode == 126) // up
		carte->translate_y -= 35;
	if (keycode == 6) // z
		carte->translate_z += 35;
	if (keycode == 7) // x
		carte->translate_z -= 35;
	if (keycode == 69)
		carte->scale += 3; //+
	if (keycode == 78)
		carte->scale -= 3; //-
	if (keycode == 8) //c
		carte->tz += 1.1;
	if (keycode == 9) //v
		carte->tz -= 1.1;
	if (keycode == 3) //f
	{
		if (carte->bool_flat == 0)
			carte->bool_flat = 1;
		else
			carte->bool_flat = 0;
	}
	if (keycode == 5) //g
	{
		if (carte->make_it_colorful == 0)
			carte->make_it_colorful = 1;
		else if (carte->make_it_colorful == 1)
			carte->make_it_colorful = 0;
		initialize_colors(carte);
	}

	if (keycode == 91) //8
		carte->rotate_x += 1;
	if (keycode == 84) // 2
		carte->rotate_x -= 1;
	if (keycode == 86) //4
		carte->rotate_y += 1;
	if (keycode == 88) //6
		carte->rotate_y -= 1;
	if (keycode == 92) //9
		carte->rotate_z += 1;
	if (keycode == 83) //1
		carte->rotate_z -= 1;
	mlx_clear_window(carte->mlx_ptr, carte->win_ptr);
	connect_dots(carte);
}

int key_hook(int keycode, map *carte)
{
	if (keycode == 53)
	{
		mlx_destroy_window(carte->mlx_ptr, carte->win_ptr);
		carte->win_ptr = NULL;
		exit(0);
	}
	else
		translation(keycode, carte);
	return (0);
}

int main(int argc, char **argv)
{
	map carte;
	(void)argc;
	initialize_map(&carte);
	file_error(argc, argv);
	get_map_infos(&carte, argv[1]);
	
	initialize_matrix(&carte);
	fill_the_matrix(&carte, argv[1]);
	// display_map(&carte);

	
	connect_dots(&carte);
	mlx_key_hook(carte.win_ptr, key_hook, &carte); // esc key press event
	mlx_loop(carte.mlx_ptr);
	return (0);
}
