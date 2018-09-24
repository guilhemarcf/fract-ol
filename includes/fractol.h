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


# define W_W 2000
# define W_H 1350


typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	void		*i_p;
	int			draw;
	int			keycode;

	char		*image;
	int			bpp;
	int			size_line;
	int			endian;

	double		red_incr;
	double		green_incr;
	double		blue_incr;
	double		mwparam;

	int			reg1;
	int			reg2;
	int			reg3;

	double		x1;
	double		y1;
	double		x2;
	double		y2;
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
void			plot_line(t_win *win);

/*
** Functions of the file "MOUSE.C"
*/

int				mouse_hook(int button, int x, int y, t_win *win);
int				motion_hook(int x, int y, t_win *win);
void			set_mwparam(int button, t_win *win);

/*
** Functions of the file "KEYS.C"
*/

void			act_on_key(t_win *win);
int				key_hook(int keycode, t_win *win);

/*
** Functions of the file "IMAGES.C"
*/

void			init_img(t_win *win);
void			set_gradient(t_win *win);

/*
** Functions of the file "COLOR.C"
*/

void			set_color_incrs(t_win *win);
int				set_color(t_win *win, int i, int j);
int				calc_color(int red, int green, int blue);

#endif