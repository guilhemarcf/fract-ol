/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:55:40 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/10/04 20:55:41 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	change_zoom(t_win *win)
{
	if (win->keycode == 6 && (win->zoom >= 2))
		win->zoom *= 0.5;
	else if (win->keycode == 0 && (win->zoom <=1000))
		win->zoom *= 2.0;
}

void	zoom_in_offset_mouse(t_win *win)
{
	if (win->pp.x > app_sclx(W_W / 2, win))
		win->offx += (win->pp.x - app_sclx(W_W / 2, win)) / (double)win->zoom;
	else
		win->offx -= (app_sclx(W_W / 2, win) - win->pp.x) / (double)win->zoom;
	if (win->pp.y > app_scly(W_H / 2, win))
		win->offy += (win->pp.y - app_scly(W_H / 2, win)) / (double)win->zoom;
	else
		win->offy -= (app_scly(W_H / 2, win) - win->pp.y) / (double)win->zoom;
}

void	zoom_out_offset_mouse(t_win *win)
{
	if (win->pp.x > app_sclx(W_W / 2, win))
		win->offx -= (win->pp.x - app_sclx(W_W / 2, win)) / (double)win->zoom;
	else
		win->offx += (app_sclx(W_W / 2, win) - win->pp.x) / (double)win->zoom;
	if (win->pp.y > app_scly(W_H / 2, win))
		win->offy -= (win->pp.y - app_scly(W_H / 2, win)) / (double)win->zoom;
	else
		win->offy += (app_scly(W_H / 2, win) - win->pp.y) / (double)win->zoom;
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
	zoom_in_offset_mouse(win);
	win->px.x = (x_max - ((x_max - win->pp.x) / (double)win->zoom));
	win->px.y = (win->pp.y / (double)win->zoom);
	win->py.x = (win->pp.x / (double)win->zoom);
	win->py.y = (y_max - (((y_max - win->pp.y) / (double)win->zoom)));
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
	zoom_out_offset_mouse(win);
	win->px.x = (x_max + ((x_max - win->pp.x) / (double)win->zoom));
	win->px.y = -1 * (win->pp.y / (double)win->zoom);
	win->py.x = -1 * (win->pp.x / (double)win->zoom);
	win->py.y = (y_max + (((y_max - win->pp.y) / (double)win->zoom)));
	win->scaley = win->py.y - win->px.y;
	win->scalex = (win->scaley * W_W) / (double)W_H;
}
