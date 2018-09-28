/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:46:17 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/24 01:46:17 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

double		apply_scalex(int j, t_win *win)
{
	return (((j - (W_W / 2)) * win->scalex) / (double)W_W);
}

double		apply_scaley(int i, t_win *win)
{
	return (((i - (W_H / 2)) * win->scaley) / (double)W_H);
}

void	set_offsetx(t_win *win, int x, int flag)
{
	double offx;

	offx = 0.1 * apply_scalex(x, win);
	if (flag == 0)
	{
		win->offx += offx;
	}
	else
	{
		win->offx -= offx;
	}
}

void	set_offsety(t_win *win, int y, int flag)
{
	double offy;

	offy = 0.1 * apply_scaley(y, win);
	if (flag == 0)
		win->offy += offy;
	else
		win->offy -= offy;
}

int		get_relx(int x)
{
	if (x < W_W / 2)
		return ((W_W / 2) - x);
	else
		return (x - (W_W / 2));
}

int		get_rely(int y)
{
	if (y < W_H / 2)
		return ((W_H / 2) - y);
	else
		return (y - (W_H / 2));
}

//https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c#