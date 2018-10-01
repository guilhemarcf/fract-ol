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
	printf(" x_max = %lf\n y_max = %lf\n x_min = %lf\n y_min = %lf\n",
		x_max, y_max, x_min, y_min);
	printf(" x_range = %lf\n y_range = %lf\n",
				(x_max - x_min), (y_max - y_min));
	printf("--------------------------------------------------\n");


	win->px.x = (x_max - ((x_max - win->pp.x) / (double)ZOOM));
	win->px.y = (win->pp.y / (double)ZOOM);


	win->py.x = (win->pp.x / (double)ZOOM);
	win->py.y = (y_max - (((y_max - win->pp.y) / (double)ZOOM)));


	win->scaley = win->py.y - win->px.y;
	win->scalex = (win->scaley * W_W) / (double)W_H;


	//win->offx = win->py.x;
	//win->offy = win->px.y;
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
	printf(" x_max = %lf\n y_max = %lf\n x_min = %lf\n y_min = %lf\n",
		x_max, y_max, x_min, y_min);
	printf(" x_range = %lf\n y_range = %lf\n",
				(x_max - x_min), (y_max - y_min));
	printf("--------------------------------------------------\n");


	win->px.x = -(x_max + ((x_max - win->pp.x) / (double)ZOOM));
	win->px.y = (win->pp.y / (double)ZOOM);


	win->py.x = -(win->pp.x / (double)ZOOM);
	win->py.y = (y_max + (((y_max - win->pp.y) / (double)ZOOM)));


	win->scaley = win->py.y - win->px.y;
	win->scalex = (win->scaley * W_W) / (double)W_H;


	//win->offx = win->py.x;
	//win->offy = win->px.y;
}















