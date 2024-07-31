/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:41 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/26 15:28:19 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		fractol.title = av[1];
		if (ac == 4 && !ft_strcmp(av[1], "julia"))
		{
			fractol.julia_x = atodbl(av[2]);
			fractol.julia_y = atodbl(av[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		putstr_fd("Por favor coloca \n\t./fractol mandelbrot " \
				"ou \n\t./fractol julia <value 1> <value 2>\n", 1);
		exit(0);
	}
}
