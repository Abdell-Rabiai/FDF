/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:29:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 16:21:28 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	assign_xyzcolor(char *numbers, t_map *carte, int i, int j)
{
	if (ft_strchar(numbers, ','))
		(carte->matrix[i][j]).color_z = get_color(numbers);
	else
		(carte->matrix[i][j]).color_z = 0xffffff;
	(carte->matrix[i][j]).z = ft_atoi(numbers);
	(carte->matrix[i][j]).y = i;
	(carte->matrix[i][j]).x = j;
}

void	fill_the_matrix(t_map *carte, char *filename)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**numbers;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("ERROR  !!");
	while (++i < carte->height)
	{
		line = get_next_line(fd);
		numbers = ft_split(line, ' ');
		j = 0;
		while (numbers[j] && j < carte->width)
		{
			assign_xyzcolor(numbers[j], carte, i, j);
			j++;
		}
		free(line);
		ft_free_split(numbers);
	}
	close(fd);
}
