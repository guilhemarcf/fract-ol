/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:01:11 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 21:01:12 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

/*
** Whenever a key is pressed, its value is stored and a function that will
** decide what to do with it is called.
*/

int		key_hook(int keycode, t_win *win)
{
	win->keycode = keycode;
	act_on_key(win);
	return (keycode);
}

/*
** This function checks which key was pressed and directs the execution the
** the corresponding function.
*/

void	act_on_key(t_win *win)
{
	if (win->keycode == 53)
		exit(0);
	else if (win->keycode == 14)
		able_julia(win);
	else if (win->keycode == 15)
		reset_img(win);
	else if (win->keycode == 45 || win->keycode == 46)
		change_fract(win);
	else if (win->keycode == 24 || win->keycode == 27)
		change_mandelheads(win);
	else if (win->keycode >= 1 && win->keycode <= 3)
		change_color_incr_up(win);
	else if (win->keycode >= 7 && win->keycode <= 9)
		change_color_incr_down(win);
	else if (win->keycode >= 123 && win->keycode <= 126)
		change_offset_keys(win);
	else if (win->keycode == 4 || win->keycode == 5)
		change_color_pal(win);
	else if (win->keycode == 0 || win->keycode == 6)
		change_zoom(win);
	else if (win->keycode == 38 || win->keycode == 40)
		change_iters(win);
}

/*
** This function allows moving the image with the keys. It will always
** translade 5% in any direction.
*/

void	change_offset_keys(t_win *win)
{
	if (win->keycode == 123)
		win->offx -= 0.05 * win->scalex;
	else if (win->keycode == 126)
		win->offy -= 0.05 * win->scaley;
	else if (win->keycode == 124)
		win->offx += 0.05 * win->scalex;
	else if (win->keycode == 125)
		win->offy += 0.05 * win->scaley;
}
