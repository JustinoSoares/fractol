/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoares <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:21:05 by jsoares           #+#    #+#             */
/*   Updated: 2024/07/26 15:28:30 by jsoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH   800
# define HEIGHT  800
# define MAX_ITER 100
# define BLACK   0x000000
# define CYAN    0x00FFFF
# define WHITE	0xFFFFFF
# define Y_LIGHT 0xFFDC00
# define YELLOW 0x001F3F

typedef struct s_complex{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	int			bpp;
	int			endian;
	int			line_len;
	void		*img_ptr;
	char		*pixels_ptr;
}	t_img;

typedef struct s_fractol
{
	int			interations_definition;
	double		scape_value;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	void		*mlx;
	void		*mlx_win;
	char		*title;
	t_img		img;
}	t_fractol;

int			key_handler(int keysym, t_fractol *fractol);
int			julia_track(int x, int y, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			ft_strcmp(char *s1, char *s2);
double		atodbl(char *s);
void		putstr_fd(char *str, int fd);
void		fractol_init(t_fractol *fractol);
double		map(int unscaled_num, double new_min, \
		double new_max, double old_max);
void		fractol_render(t_fractol *fractol);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
