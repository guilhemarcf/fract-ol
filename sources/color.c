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
/*
int				saturate_max_incr(t_win *win)
{
	int		red;
	int		green;
	int		blue;

	if (win->red_incr >= win->green_incr && win->red_incr >= win->blue_incr)
		red = 255;
	else
		red = 0;
	if (win->green_incr >= win->red_incr && win->green_incr >= win->blue_incr)
		green = 255;
	else
		green = 0;
	if (win->blue_incr >= win->red_incr && win->blue_incr >= win->green_incr)
		blue = 255;
	else
		blue = 0;
	return (calc_color(red, green, blue));
}
*/


int				calc_color2(int red, int green, int blue)
{
	(void)red;
	(void)green;
	(void)blue;
	return (1);
}

/*
** This functions puts different values of red, green and blue into a single
** big endian integer.
*/

int				calc_color1(int red, int green, int blue)
{
	int color;

	color = red << 16 | green << 8 | blue;
	return (color);
}

/*
** This functinos is still gonna change a lot!
*/

int				set_color(int color, t_win *win)
{
	int		hexcolor;
	int		red;
	int		green;
	int		blue;

	if (color < ITERS && color > 0)
	{
		red = (color / (double)ITERS) * (win->red_incr * 32 - 1);
		green = (color / (double)ITERS) * (win->green_incr * 32 - 1);
		blue = (color / (double)ITERS) * (win->blue_incr * 32 - 1);
		hexcolor = calc_color1(red, green, blue);
		return (hexcolor);
	}
	else
		return (0x000000);
}
