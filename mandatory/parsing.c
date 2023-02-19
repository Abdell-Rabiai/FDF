/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:19:44 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/19 13:47:56 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_lines(char *line, int fd)
{
	int		line1_width;
	int		line_wid;

	line1_width = ft_how_many_words(line, ' ');
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_wid = ft_how_many_words(line, ' ');
		if (line1_width > line_wid)
		{
			ft_printf("OOps,The Map Is Not Formatted Properely!\n");
			exit(EXIT_FAILURE);
		}
		free(line);
	}
}

void	map_check(char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("OOps, The Map Is Empty!\n");
		exit(EXIT_FAILURE);
	}
	check_lines(line, fd);
}
