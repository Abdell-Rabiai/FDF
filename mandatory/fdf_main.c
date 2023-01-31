/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:53 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/31 22:28:37 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void translation(int keycode, map *carte, bresenham *bres)
{
    /*124 right 125 down 123 left 126* up*/ 
    printf("%d\n", keycode);
    if (keycode == 123)
        carte->translate_x -= 10;
    else if (keycode == 124)
        carte->translate_x += 10;
    else if (keycode == 125)
        carte->translate_y -= 10;
    else if (keycode == 126)
        carte->translate_y += 10;
    else
        return ;
    (void) bres;
    // mlx_clear_window(carte->mlx_ptr, carte->win_ptr);
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
    // printf("color_z : %d\n", bres->color_z);
        translation(keycode, carte, carte->bres);
    //    mlx_clear_window(carte->mlx_ptr, carte->win_ptr);
	return (0);
}

int main(int argc, char **argv)
{
    map carte;

    file_error(argc, argv);
    get_map_infos(&carte, argv[1]);
    
    carte.mlx_ptr = mlx_init();
    printf("HELLO 0\n");
    carte.win_ptr = mlx_new_window(carte.mlx_ptr, WIDTH, HEIGHT, "fill de fer");
    carte.scale = 20;
    
    connect_dots(&carte);
    printf("HELLO 1\n");
    mlx_key_hook(carte.win_ptr, key_hook, &carte); // esc key press event
    mlx_loop(carte.mlx_ptr);
	return (0);
}
