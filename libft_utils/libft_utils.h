/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:05:33 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/02 21:01:53 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

size_t	ft_strlen(const char *str);
int ft_atoi(const char *str);
int ft_atohex(const char *str);
int	get_index_base(int c, int base);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void file_error(int argc, char **argv);

/*split*/
int		ft_how_many_words(const char *s, char c);
char	**ft_free_split(char **strings);
int		ft_get_length_of_word(const char *s, char c);
char	*return_the_first_word(const char *s, char c);
char	**ft_split(char const *s, char c);

#endif