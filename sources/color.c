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

int				set_color1(int ite, t_win *win)
{
	int		hexcolor;
	int		red;
	int		green;
	int		blue;

	if (ite < win->iters)
	{
		red = (ite / (double)win->iters) * (win->red_incr * 32 - 1);
		green = (ite / (double)win->iters) * (win->green_incr * 32 - 1);
		blue = (ite / (double)win->iters) * (win->blue_incr * 32 - 1);
		hexcolor = red << 16 | green << 8 | blue;
		return (hexcolor);
	}
	else
		return (0xFFFFFF);
}


int				set_color2(int ite, t_win *win)
{
	if (ite < win->iters)
		return ((0x0000FF % (int)win->iters) << ite);
	else
		return (0xFFFFFF);
}


int				set_color3(int ite, t_win *win)
{
	int		hexcolor;

	(void)win;
	if (ite < win->iters)
	{
		hexcolor = 16777216 * (ite / (double)win->iters);
		return (hexcolor);
	}
	else
		return (0xFFFFFF);
}

int				set_color4(int ite, t_win *win)
{
	int		hexcolor;

	(void)win;
	if (ite < win->iters)
	{
		hexcolor = 16777216 * ((win->iters - ite) / (double)win->iters);
		return (hexcolor);
	}
	else
		return (0xFFFFFF);
}
