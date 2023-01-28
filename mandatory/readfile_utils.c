/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:44:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/28 03:47:50 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_file_format(char *filename)
{
	char *extension;

	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (0);
	if (ft_strncmp(extension, ".fdf", ft_strlen(extension)) == 0)
		return (1);
	else 
		return (0);
}

void file_error(int argc, char **argv)
{
	int fd;

	if (argc != 2)
    {
        ft_printf("ERROR : invalid number of arguments.\n");
        ft_printf("USAGE : ./fdf map.fdf \n");
        exit(EXIT_FAILURE);
    }
    if (check_file_format(argv[1]) == 0)
    {
        ft_printf("EROOR : incorrect file format\nit should be *.fdf\n");
        exit(EXIT_FAILURE);
    }
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("cannot open the file");
		exit(EXIT_FAILURE);
	}
}

int get_map_height(char *filename)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		perror("EROOR ");
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int get_map_width(char *filename)
{
	int i;
	int fd;
	char *fline;

	i = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		perror("EROOR ");
	fline = get_next_line(fd);
	i = ft_how_many_words(fline, ' ');
	free(fline);
	close(fd);
	return (i);
}

void get_map_infos(map *carte, char *filename)
{
	int i;

	i = 0;
	(void)carte;
	carte->height = get_map_height(filename);
	carte->width = get_map_width(filename);
	if (carte->width <= 0 || carte->height <= 0)
		ft_printf("ERROR : incorrect heght and width values of the file\n");
	// check that all rows have columns of the same size height
	
	carte->matrice = (int **)malloc(sizeof(int *) * (carte->height + 1));
	if(!carte->matrice)
		perror("ERROR allocating memory for the map\n");
	while (i < carte->height)
	{
		carte->matrice[i] = (int *)malloc(sizeof(int) * (carte->width + 1));
		if (!carte->matrice[i])
			perror("ERROR allocating memory for map rows");
		i++;
	}
	printf("carte width : %d\t, carte height : %d\n", carte->width, carte->height);
	fill_the_matrix(carte, filename);
	i = 0;
	printf("%d %d %d\n",carte->matrice[0][0], carte->matrice[0][1], carte->matrice[0][2]);
	// while (i < carte->height)
	// {
	// 	for (int j = 0; j < carte->width; j++)
	// 		printf("%d  ", carte->matrice[i][j]);
	// 	i++;
	// 	printf("\n");
	// }
}