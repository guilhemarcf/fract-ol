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

int		motion_hook(int x, int y, t_win *win)
{
	win->p_inst.x = x;
	win->p_inst.y = y;
	return (1);
}

int		mouse_hook(int button, int x, int y, t_win *win)
{
	printf("button: %d | x: %lf | y: %lf\n------------------------------------------\n",button, app_sclx(x, win), app_scly(y, win));
	if (button == 4)
	{
		zoom_in(win, x, y);
	}
	else if (button == 5)
	{
		zoom_out(win, x, y);
	}
	plot_image(win);
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















