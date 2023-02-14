/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgae_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:56:25 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 13:02:12 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int exit_hook()
{
	exit(0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int create_argb(int a, int r, int g, int b) // 2 200 250
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		exit(0);
	}
	return (0);
}

int prtimage()
{
	int color;
	t_vars vars;
	t_data image;

	int img_width = 1000;
	int img_height = 700;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
        perror("EROOR : ");
	vars.win = mlx_new_window(vars.mlx, img_width, img_height, "Fill de fer");
	if (vars.win == NULL)
	{
		free(vars.win);
        perror("EROOR : ");
	}
	image.img = mlx_new_image(vars.mlx, img_width, img_height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	for (int i = 0; i < img_height - 1; i++)
	{
		for (int j = 0; j < img_width - 1; j++)
		{
			double r = (double)(img_width - j) / (img_width - 1);
			double g = (double)(i) / (img_height - 1);
			double b = 1;
			color = ((int)(255 * r) << 16) + ((int)(255 * g) << 8) + ((int)(255 * b));
			my_mlx_pixel_put(&image, j, i, color);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);
	free(vars.mlx);
	return (0);
}

int main()
{
	prtimage();
	return 0;
}