/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:53 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 17:28:39 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_hook(void)
{
	exit(0);
}

void	all_hooks(int keycode, t_map *carte)
{
	ft_printf("%d\n", keycode);
	translation_hooks(keycode, carte);
	scalling_hooks(keycode, carte);
	colors_and_projection_hooks(keycode, carte);
	rotation_hooks(keycode, carte);
	mlx_destroy_image(carte->mlx_ptr, carte->image.img);
	mlx_clear_window(carte->mlx_ptr, carte->win_ptr);
	carte->image.img = mlx_new_image(carte->mlx_ptr, WIDTH, HEIGHT);
	carte->image.addr = mlx_get_data_addr(carte->image.img,
			&carte->image.bits_per_pixel, &carte->image.line_length,
			&carte->image.endian);
	connect_dots(carte);
	mlx_put_image_to_window(carte->mlx_ptr, carte->win_ptr,
		carte->image.img, 0, 0);
}

int	key_hook(int keycode, t_map *carte)
{
	if (keycode == 53)
	{
		mlx_destroy_window(carte->mlx_ptr, carte->win_ptr);
		carte->win_ptr = NULL;
		system("leaks fdf");
		exit(0);
	}
	else
		all_hooks(keycode, carte);
	return (0);
}

void	put_strings(t_map *carte)
{	
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 10, 0xffffab,
		"\t\t//------>USAGE GUIDE<------//\n\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 40, 0xffffab,
		"use ARROWS UP DOWN LEFT RIGHT for translation\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 70, 0xffffab,
		"use Z and X to move all the points with z!=0 up and down\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 100, 0xffffab,
		"use C and V to stretch the segments with z!=0 up and down\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 130, 0xffffab,
		"use 4 and 6 to rotate the shape around the axis X\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 160, 0xffffab,
		"use 2 and 8 to rotate the shape around the axis Y\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 190, 0xffffab,
		"use G to make the shape colorful\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 220, 0xffffab,
		"use F to apply the isometric projection\n");
	mlx_string_put(carte->mlx_ptr, carte->win_ptr, WIDTH - 650, 250, 0xffffab,
		"click ENTER to make the guide dissapear\n");
}

int	main(int argc, char **argv)
{
	t_map	carte;

	initialize_map(&carte);
	file_error(argc, argv);
	get_map_infos(&carte, argv[1]);
	initialize_matrix(&carte);
	fill_the_matrix(&carte, argv[1]);
	connect_dots(&carte);
	mlx_put_image_to_window(carte.mlx_ptr, carte.win_ptr,
		carte.image.img, 0, 0);
	mlx_hook(carte.win_ptr, 2, 0, key_hook, &carte);
	mlx_hook(carte.win_ptr, 17, 0, exit_hook, 0);
	mlx_loop(carte.mlx_ptr);
	return (0);
}
