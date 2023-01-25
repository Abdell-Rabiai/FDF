/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:56:25 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/24 20:21:31 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
 
int		create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int main()
{
    
    void *mlx = mlx_init();
    
    int width = 1000;
    int height = 700;
    int x_o = width/2;
    int y_o = height/2;
    int r = width/4;
    
    void *win = mlx_new_window(mlx, width, height, "Fill De Fer");
    (void)win;
     
    for (int j = height; j > 0 ; j--)
    {   
        mlx_pixel_put(mlx, win, x_o, j, 0XBE00FF);
    }
    for (int j = width; j > 0 ; j--)
    {
        mlx_pixel_put(mlx, win, j, y_o, 0XBE00FF);
    }
 
    for (int i = 0; i < r; i++)
    {
        for (int j = x_o, i = y_o; j < width*3/4 && i < height*3/4; j++, i++)
        {
            mlx_pixel_put(mlx, win, j, i, 0XBE00FF);
        }
        x_o--;
        y_o++;
    }
    
    mlx_loop(mlx);
    
    return 0;
}