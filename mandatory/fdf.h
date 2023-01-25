/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:53:05 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/23 15:36:17 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

size_t	ft_strlen(const char *str);
int		ft_printf(const char *string_format, ...);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_how_many_words(const char *s, char c);
char	**ft_free_split(char **strings);
int		ft_get_length_of_word(const char *s, char c);
char	*return_the_first_word(const char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif