/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:19:39 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 20:19:40 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "./../minilibx_macos/mlx.h"
# include "./../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define W_W 1350
# define W_H 900
# define ITERS 50

typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	void		*i_p;
	int			keycode;

	char		*image;
	int			bpp;
	int			size_line;
	int			endian;

	int			fract;

	int			instx;
	int			insty;

	double		offx;
	double		offy;
	double		scalex;
	double		scaley;

	int			red_incr;
	int			green_incr;
	int			blue_incr;
}				t_win;

/*
** Functions of the file "MAIN.C"
*/

t_win			*init_window(void);
int				main(void);

/*
** Functions of the file "PRINTS.C"
*/

void			error(void);
void			plot_image(t_win *win);//, int (*f)(double, ...));

/*
** Functions of the file "MOUSE.C"
*/

int				mouse_hook(int button, int x, int y, t_win *win);
int				motion_hook(int x, int y, t_win *win);
void			set_scale(int button, t_win *win, int x, int y);

/*
** Functions of the file "KEYS.C"
*/

void			act_on_key(t_win *win);
int				key_hook(int keycode, t_win *win);
void			change_fract(t_win *win);
void			change_color_incr1(t_win *win);
void			change_color_incr2(t_win *win);

/*
** Functions of the file "IMAGES.C"
*/

void			init_img(t_win *win);
void			put_pixel_img(t_win *win, int x, int y, int color);

/*
** Functions of the file "COLOR.C"
*/

int				set_color(int color, t_win *win);
int				calc_color(int red, int green, int blue);

/*
** Functions of the file "COMPLEX.C"
*/

void			squarefy_complex(double re_base, double im_base,
										double *re_res, double *im_res);
double			module_complex(double re, double im);
int				iterate_mandel(double y, double x);
//int				iterate_julia(double y, double x);

/*
** Functions of the file "SCALING.C"
*/

double			apply_scalex(int j, t_win *win);
double			apply_scaley(int i, t_win *win);
void			set_offsetx(t_win *win, int x, int flag);
void			set_offsety(t_win *win, int y, int flag);
int				get_relx(int x);
int				get_rely(int y);

#endif