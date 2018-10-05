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
** This functinos is still gonna change a lot!
*/

int				set_color1(int ite, t_win *win)
{
	int		hexcolor;
	int		red;
	int		green;
	int		blue;

	if (ite < win->iters && ite > 0)
	{
		red = (ite / (double)win->iters) * (win->red_incr * 32 - 1);
		green = (ite / (double)win->iters) * (win->green_incr * 32 - 1);
		blue = (ite / (double)win->iters) * (win->blue_incr * 32 - 1);
		hexcolor = red << 16 | green << 8 | blue;
		return (hexcolor);
	}
	else
		return (0x000000);
}


int				set_color2(int ite, t_win *win)
{
	int		hexcolor;
	int		red;
	int		green;
	int		blue;

	if (ite < win->iters && ite > 0)
	{
		red = ((double)win->iters - (ite / (double)win->iters)) *
							(win->red_incr * 32 - 1);
		green = ((double)win->iters - (ite / (double)win->iters)) *
							(win->green_incr * 32 - 1);
		blue = ((double)win->iters - (ite / (double)win->iters)) *
							(win->blue_incr * 32 - 1);
		hexcolor = red << 16 | green << 8 | blue;
		return (hexcolor);
	}
	else
		return (0x000000);
}


int				set_color3(int ite, t_win *win)
{
	int		hexcolor;

	(void)win;
	if (ite < win->iters && ite > 0)
	{
		hexcolor = 16777216 * (ite / (double)win->iters);
		return (hexcolor);
	}
	else
		return (0x000000);
}

int				set_color4(int ite, t_win *win)
{
	int		hexcolor;

	(void)win;
	if (ite < win->iters && ite > 0)
	{
		hexcolor = 16777216 * ((win->iters - ite) / (double)win->iters);
		return (hexcolor);
	}
	else
		return (0x000000);
}


void	change_color_pal(t_win *win)
{
	if (win->keycode == 4)
	{
		if (win->color_pal < 3)
			win->color_pal++;
		else
			win->color_pal = 0;
	}
	else if (win->keycode == 5)
	{
		if (win->color_pal > 0)
			win->color_pal--;
		else
			win->color_pal = 3;
	}
}