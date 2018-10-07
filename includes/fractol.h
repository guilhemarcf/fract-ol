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

# define W_W 1300
# define W_H 1000

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	void		*i_p;

	int			keycode;
	int			mode;
	int			fract;
	int			move_screen;
	int			odd_read;
	int			color_pal;
	int			julia_enable;
	int			mandelheads;

	int			fract_beckup;

	char		*image;
	int			bpp;
	int			size_line;
	int			endian;
	double		iters;
	double		zoom;

	double		offx;
	double		offy;
	double		scalex;
	double		scaley;
	double		x_range;
	double		y_range;

	t_point		p_inst;
	t_point		p_julia;
	t_point		p1;
	t_point		p2;
	t_point		pp;
	t_point		px;
	t_point		py;

	int			red_incr;
	int			green_incr;
	int			blue_incr;
}				t_win;

/*
** Functions from "MAIN.C" 
*/

t_win			*set_window(void);
t_win			*init_window(int fracnum);
void			init_img(t_win *win, int fracnum);
int				main(int ac, char **av);

/*
** Functions from "IMAGES.C"
*/

void			reset_img(t_win *win);
void			put_pixel_img(t_win *win, int y, int x, int color);
void			change_mandelheads(t_win *win);
void			change_iters(t_win *win);
void			change_fract(t_win *win);

/*
** Functions from "PLOT_IMAGE.C"
*/

int				get_iterations(t_win *win, int i, int j);
void			plot_image(t_win *win);

/*
** Functions from "FRACTALS.C"
*/

int				iterate_mandel(double re_base, double im_base, t_win *win);
int				iterate_julia(double re_base, double im_base, t_win *win);
int				iterate_tricorn1(double re_base, double im_base, t_win *win);
int				iterate_tricorn2(double re_base, double im_base, t_win *win);
int				iterate_ship(double re_base, double im_base, t_win *win);

/*
** Functions from "JULIA_EXT.C"
*/

void			able_julia(t_win *win);
void			follow_julia(int x, int y, t_win *win);

/*
** Functions from "COMPLEX.C"
*/

t_complex		multiply_complex(t_complex z1, t_complex z2);
t_complex		pow_complex(t_complex z, int power);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		get_complex(t_complex *z, double re, double im);
int				module_smaller_than_2(t_complex z);

/*
** Functions from "SCALING.C"
*/

double			app_sclx(int j, t_win *win);
double			app_scly(int i, t_win *win);

/*
** Functions from "COLOR.C"
*/

int				set_color1(int ite, t_win *win);
int				set_color2(int ite, t_win *win);
int				set_color3(int ite, t_win *win);
int				set_color4(int ite, t_win *win);

/*
** Functions from "COLOR_EXT.C"
*/

void			change_color_incr_up(t_win *win);
void			change_color_incr_down(t_win *win);
void			change_color_pal(t_win *win);

/*
** Functions from "MOUSE.C"
*/

int				motion_hook(int x, int y, t_win *win);
void			mouse_follow(int x, int y, t_win *win);
int				mouse_press(int button, int x, int y, t_win *win);
int				mouse_release(int button, int x, int y, t_win *win);
void			clear_points(t_win *win);

/*
** Functions from "ZOOM.C"
*/

void			change_zoom(t_win *win);
void			zoom_in_offset_mouse(t_win *win);
void			zoom_out_offset_mouse(t_win *win);
void			zoom_in(t_win *win, int x, int y);
void			zoom_out(t_win *win, int x, int y);

/*
** Functions from "KEYS.C"
*/

int				key_hook(int keycode, t_win *win);
void			act_on_key(t_win *win);
void			change_offset_keys(t_win *win);

/*
** Functions from "PRINTS.C"
*/

void			error(void);
void			usage(void);

#endif