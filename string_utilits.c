/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utilits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:32:54 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/26 15:32:55 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	aux(char *s, int i, int sign)
{
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
}

double	atodbl(char *s)
{
	int		res;
	int		sign;
	int		i;
	double	res2;
	double	pow;

	res = 0;
	res2 = 0;
	pow = 1;
	sign = 1;
	i = 0;
	aux(s, i, sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i++] - 48);
	}
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		pow /= 10;
		res2 = res2 + (s[i++] - 48) * pow;
	}
	return ((res + res2) * sign);
}
