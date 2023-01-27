/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:44:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/27 18:27:35 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_file_format(char *filename)
{
	char *extension;

	extension = ft_strrchr(filename, '.');
	puts(extension);
	if (extension == NULL)
		return (0);
	printf("%zu\n", ft_strlen(extension));
	if (ft_strncmp(extension, ".fdf", ft_strlen(extension)) == 0)
		return (1);
	else 
		return (0);
}

void file_error(int argc, char **argv)
{
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
}