/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:34:47 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/28 16:34:49 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	mandelbrot_vs_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!strcmp(fractol->title, "julia"))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandelbrot_vs_julia(&z, &c, fractol);
	while (i < fractol->interations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > fractol->scape_value)
		{
			color = map(i, YELLOW, Y_LIGHT, fractol->interations_definition);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, CYAN);
}

void	fractol_render(t_fractol *fractol)
{
	static int	x;
	static int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, \
	fractol->img.img_ptr, 0, 0);
}
