/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:48:25 by arabiai           #+#    #+#             */
/*   Updated: 2023/01/27 23:51:19 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int ft_iswspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	int sign;
	long double res;

	sign = 1;
	res = 0;
	while (*str && ft_iswspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		if (sign > 0 && res >= 9223372036854775807UL)
			return (-1);
		if (sign < 0 && res >= 9223372036854775808UL)
			return (0);
		str++;
	}
	return (res * sign);
}