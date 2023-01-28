/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:29:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/28 03:53:09 by arabiai          ###   ########.fr       */
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
	line = get_next_line(fd);
	printf("first line %s\n", line);
	while (i < carte->height )
	{
		numbers = ft_split(line, ' ');
		j = 0;
		// printf("world 2\n");
		while (j < carte->width)
		{
			carte->matrice[i][j] = ft_atoi(numbers[j]);
			j++;
		}
		// printf("from 3\n");
		free(line);
		ft_free_split(numbers);
		i++;
	}
	close(fd);
}