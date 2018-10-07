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
	if (win->move_screen == 1)
		mouse_follow(x, y, win);
	else if (win->fract == 1)
		follow_julia(x, y, win);
	return (1);
}

void	mouse_follow(int x, int y, t_win *win)
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
