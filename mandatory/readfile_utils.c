/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:44:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/30 18:51:09 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void display_map(map *carte)
{
	int i;

	i = 0;
	while (i < carte->height)
	{
		for (int j = 0; j < carte->width; j++)
			printf("%3d", carte->matrice[i][j]);
		i++;
		printf("\n");
	}
}

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

void get_map_dimensions(char *filename, map *carte)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		perror("EROOR ");
	line = get_next_line(fd);
	carte->width = ft_how_many_words(line, ' ');
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	carte->height = i;
}

void get_map_infos(map *carte, char *filename)
{
	int i;

	i = 0;
	get_map_dimensions(filename, carte);

	if (carte->width <= 0 || carte->height <= 0)
		ft_printf("ERROR : incorrect heght and width values of the file\n");	
	carte->matrice = (int **)malloc(sizeof(int *) * (carte->height + 1));
	if(!carte->matrice)
		perror("ERROR allocating memory for the map\n");
	while (i < carte->height)
	{
		carte->matrice[i] = (int *)malloc(sizeof(int) * (carte->width));
		if (!carte->matrice[i])
			perror("ERROR allocating memory for map rows");
		i++;
	}
	printf("carte width : %d\t, carte height : %d\n", carte->width, carte->height);
	fill_the_matrix(carte, filename);
	display_map(carte);
}