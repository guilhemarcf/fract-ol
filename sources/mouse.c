/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:20:27 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 21:20:28 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int		mouse_press(int button, int x, int y, t_win *win)
{
	if (button == 1)
		win->move_screen = 1;
	else if (button == 4)
		zoom_in(win, x, y);
	else if (button == 5)
		zoom_out(win, x, y);
	plot_image(win);
	return (1);
}

int		mouse_release(int button, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (button == 1)
		clear_points(win);
	return (1);
}

void	clear_points(t_win *win)
{
	win->odd_read = 0;
	win->move_screen = 0;
	win->p1.x = app_sclx(W_W / 2, win);
	win->p1.y = app_scly(W_H / 2, win);
	win->p2.x = app_sclx(W_W / 2, win);
	win->p2.y = app_scly(W_H / 2, win);
}

int		motion_hook(int x, int y, t_win *win)
{
	if (win->move_screen == 1)
	{
		win->p_inst.x = app_sclx(x, win);
		win->p_inst.y = app_scly(y, win);
		if (win->odd_read == 0)
		{
			win->p1.x = win->p_inst.x;
			win->p1.y = win->p_inst.y;
			win->odd_read = 1;
		}
		else
		{
			win->p2.x = win->p_inst.x;
			win->p2.y = win->p_inst.y;
			win->x_range = win->p1.x - win->p2.x;
			win->y_range = win->p1.y - win->p2.y;
			win->offx += 4 * win->x_range;
			win->offy += 4 * win->y_range;
			win->odd_read = 0;
			plot_image(win);
		}
	}
	return (1);
}

void	change_offset_mouse(t_win *win, int is_zoom_in)
{
	if (is_zoom_in)
	{
		if (win->pp.x > app_sclx(W_W / 2, win))
			win->offx += (win->pp.x - app_sclx(W_W / 2, win)) / (double)ZOOM;
		else
			win->offx -= (app_sclx(W_W / 2, win) - win->pp.x) / (double)ZOOM;
		if (win->pp.y > app_scly(W_H / 2, win))
			win->offy += (win->pp.y - app_scly(W_H / 2, win)) / (double)ZOOM;
		else
			win->offy -= (app_scly(W_H / 2, win) - win->pp.y) / (double)ZOOM;
	}
	else
	{
		if (win->pp.x > app_sclx(W_W / 2, win))
			win->offx -= (win->pp.x - app_sclx(W_W / 2, win)) / (double)ZOOM;
		else
			win->offx += (app_sclx(W_W / 2, win) - win->pp.x) / (double)ZOOM;
		if (win->pp.y > app_scly(W_H / 2, win))
			win->offy -= (win->pp.y - app_scly(W_H / 2, win)) / (double)ZOOM;
		else
			win->offy += (app_scly(W_H / 2, win) - win->pp.y) / (double)ZOOM;
	}
}

void	zoom_in(t_win *win, int x, int y)
{
	double x_max;
	double y_max;
	double x_min;
	double y_min;

	x_min = app_sclx(0, win);
	y_min = app_scly(0, win);
	x_max = app_sclx(W_W, win);
	y_max = app_scly(W_H, win);
	win->pp.x = app_sclx(x, win);
	win->pp.y = app_scly(y, win);
	print_zoom(x_min, x_max, y_min, y_max);
	change_offset_mouse(win, 1);
	win->px.x = (x_max - ((x_max - win->pp.x) / (double)ZOOM));
	win->px.y = (win->pp.y / (double)ZOOM);
	win->py.x = (win->pp.x / (double)ZOOM);
	win->py.y = (y_max - (((y_max - win->pp.y) / (double)ZOOM)));
	win->scaley = win->py.y - win->px.y;
	win->scalex = (win->scaley * W_W) / (double)W_H;
}

void	zoom_out(t_win *win, int x, int y)
{
	double x_max;
	double y_max;
	double x_min;
	double y_min;

	x_min = app_sclx(0, win);
	y_min = app_scly(0, win);
	x_max = app_sclx(W_W, win);
	y_max = app_scly(W_H, win);
	win->pp.x = app_sclx(x, win);
	win->pp.y = app_scly(y, win);
	print_zoom(x_min, x_max, y_min, y_max);
	change_offset_mouse(win, 0);
	win->px.x = (x_max + ((x_max - win->pp.x) / (double)ZOOM));
	win->px.y = -1 * (win->pp.y / (double)ZOOM);
	win->py.x = -1 * (win->pp.x / (double)ZOOM);
	win->py.y = (y_max + (((y_max - win->pp.y) / (double)ZOOM)));
	win->scaley = win->py.y - win->px.y;
	win->scalex = (win->scaley * W_W) / (double)W_H;
}















