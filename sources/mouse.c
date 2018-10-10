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

/*
** This is a function called by one of the event listeners in the main file.
** Here, depending on parameters of the win struct, it will wither direct the
** execution to moving the screen around, or changing the parameter of the
** julia set.
*/

int		motion_hook(int x, int y, t_win *win)
{
	if (win->move_screen == 1)
		mouse_follow(x, y, win);
	else if (win->fract == 1)
		follow_julia(x, y, win);
	return (1);
}

/*
** Function called in order to translate the image with the mouse. While
** the left mouse button is pressed, it will constantly refresh and update
** the points p1 and p2 with the p_inst values and make translations, by
** changing the x and y offsets of the image based on the offsets of the
** points captured in the time interval.
*/

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
		win->offx += 2 * win->x_range;
		win->offy += 2 * win->y_range;
		win->odd_read = 0;
	}
}

/*
** Whenever one of the buttons of the mouse is pressed, this function
** determines what should happen next. If it's the button on, it will
** change a win variable that will make the mouse_follow function work,
** and in case it's the mouse will, depending on which direction it spun,
** and the mouse position, it will alter the zoom.
*/

int		mouse_press(int button, int x, int y, t_win *win)
{
	if (button == 1)
		win->move_screen = 1;
	else if (button == 4)
		zoom_in(win, x, y);
	else if (button == 5)
		zoom_out(win, x, y);
	return (1);
}

/*
** Whenever the mouse button 1 is released, this function is called to
** unset the variables that make the translation with the mouse possible.
** It has to do it, otherwise mouse_follow function could be stuck in the
** middle of tracking a translation, making it give undesired leaps all over
** the image.
*/

int		mouse_release(int button, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (button == 1)
		clear_points(win);
	return (1);
}

/*
** Nulifies the difference between the points tracked by mouse_follow, so
** that it always start by where it should. Also changes the variables that
** regulate that function's behavior to the standard.
*/

void	clear_points(t_win *win)
{
	win->odd_read = 0;
	win->move_screen = 0;
	win->p1.x = app_sclx(W_W / 2, win);
	win->p1.y = app_scly(W_H / 2, win);
	win->p2.x = app_sclx(W_W / 2, win);
	win->p2.y = app_scly(W_H / 2, win);
}
