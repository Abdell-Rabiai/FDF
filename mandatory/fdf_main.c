/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:53 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/03 16:05:37 by arabiai          ###   ########.fr       */
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
    carte->tz = 1;
	
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
            (carte->matrix[i][j]).color_z = -1;
            j++;
        }
		i++;
		printf("\n");
	}
}

void translation(int keycode, map *carte)
{
    /*124 right 125 down 123 left 126* up*/ 
    printf("%d\n", keycode);
    if (keycode == 123)
        carte->translate_x -= 35;
    if (keycode == 124)
        carte->translate_x += 35;
    if (keycode == 125)
        carte->translate_y += 35;
    if (keycode == 126)
        carte->translate_y -= 35;
    if (keycode == 6) // z
        carte->translate_z += 35;
    if (keycode == 7) // x
        carte->translate_z -= 35;
    if (keycode == 69)
        carte->scale += 5; //+
    if (keycode == 78)
        carte->scale -= 5; //-
    if (keycode == 8) //c
        carte->tz += 2;
    if (keycode == 9) //v
        carte->tz -= 2;
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

    initialize_map(&carte);
    file_error(argc, argv);
    get_map_infos(&carte, argv[1]);
    
    initialize_matrix(&carte);
	fill_the_matrix(&carte, argv[1]);
	display_map(&carte);

    
    connect_dots(&carte);
    mlx_key_hook(carte.win_ptr, key_hook, &carte); // esc key press event
    mlx_loop(carte.mlx_ptr);
	return (0);
}
