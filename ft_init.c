/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:25:29 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/26 17:25:31 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Erro ao alocar memória");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol *fractol)
{
	fractol->scape_value = 4 ;
	fractol->interations_definition = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractol);
	mlx_hook(fractol->mlx_win,
		ButtonPress,
		ButtonPressMask,
		mouse_handler,
		fractol);
	mlx_hook(fractol->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractol);
	mlx_hook(fractol->mlx_win,
		MotionNotify,
		PointerMotionMask,
		julia_track,
		fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		malloc_error();
	fractol->mlx_win = mlx_new_window(fractol->mlx,
			WIDTH, HEIGHT, fractol->title);
	if (fractol->mlx_win == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len,
			&fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
