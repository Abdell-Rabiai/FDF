/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:29:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/28 01:44:14 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

// void fill_the_matrix(map *carte, char *filename)
// {
// 	int i;
// 	int j;
// 	int fd;
// 	// char *line;
// 	char **numbers;
// 	(void)carte;
// 	(void)numbers;

// 	i = 0;
// 	j = 0;
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		perror("ERROR  ");
// 	// line = get_next_line(fd);
// 	// while (line)
// 	// {
// 	// 	puts(line);
// 	// 	line = get_next_line(fd);
// 	// }
// 	// puts(get_next_line(fd));
// 	// while (line)
// 	// {
// 	// 	numbers = ft_split(line, ' ');
// 	// 	free(line);
// 	// 	while (j <= carte->width)
// 	// 	{
// 	// 		carte->matrice[i][j] = ft_atoi(numbers[j]);
// 	// 		j++;
// 	// 	}
// 	// 	line = get_next_line(fd);
// 	// 	i++;
// 	// }
// 	close(fd);
// }