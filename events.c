/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:39:53 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/29 11:39:57 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == 65451)
		fractol->interations_definition += 10;
	else if (keysym == 65453)
		fractol->interations_definition -= 10;
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == Button5)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
}

int	julia_track(int x, int y, t_fractol *fractol)
{
	if (!strcmp(fractol->title, "julia"))
	{
		fractol->julia_x = (map(x, -2, +2, WIDTH) * \
		fractol->zoom) + fractol->shift_x;
		fractol->julia_x = (map(y, +2, -2, HEIGHT) * \
		fractol->zoom) + fractol->shift_y;
		fractol_render(fractol);
	}
	return (0);
}
