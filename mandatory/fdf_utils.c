/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:29:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/28 08:56:05 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void fill_the_matrix(map *carte, char *filename)
{
	int i;
	int j;
	int fd;
	char *line;
	char **numbers;

	i = 0;
	j = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("ERROR  ");
	while (i < carte->height )
	{
		line = get_next_line(fd);
		numbers = ft_split(line, ' ');
		j = 0;
		while (j < carte->width)
		{
			carte->matrice[i][j] = ft_atoi(numbers[j]);
			j++;
		}
		free(line);
		ft_free_split(numbers);
		i++;
	}
	carte->matrice[i] = NULL;
	close(fd);
}