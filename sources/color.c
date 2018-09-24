/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:37:09 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/23 17:37:11 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void			set_color_incrs(t_win *win)
{
	win->red_incr = 255 / (double)W_H;
	win->green_incr = 255 / (double)W_H;
	win->blue_incr = 255 / (double)W_H;
}

/*
** This functions puts different values of red, green and blue into a single
** big endian integer.
*/

int				calc_color(int red, int green, int blue)
{
	int color;

	color = red << 16 | green << 8 | blue;
	return (color);
}

/*
** This functinos is still gonna change a lot!
*/

int				set_color(t_win *win, int i, int j)
{
	double		red;
	double		green;
	double		blue;

	(void)j;
	if (win->reg1)
		red = win->red_incr * i * win->mwparam;
	else
		red = 0;
	if (win->reg2)
		green = win->green_incr * i * win->mwparam;
	else
		green = 0;
	if (win->reg3)
		blue = win->blue_incr * i * win->mwparam;
	else
		blue = 0;
	return (calc_color(red, green, blue));
}