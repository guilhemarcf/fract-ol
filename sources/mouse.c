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
	win->instx = x;
	win->insty = y;
	//if (win->fract == 1)
	//	plot_image(win, &iterate_julia);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_win *win)
{
	ft_putnbr(button);
	set_scale(button, win, x, y);
	plot_image(win);
	return (1);
}


void	set_scale(int button, t_win *win, int x, int y)
{
	if (button == 4)
	{
		win->scaley = win->scaley * 1.05;
		win->scalex = (win->scaley * W_W) / W_H;
		set_offsetx(win, get_relx(x), 1);
		set_offsety(win, get_rely(y), 1);
	}
	else if (button == 5)
	{
		win->scaley = win->scaley * 0.9523809;
		win->scalex = (win->scaley * W_W) / W_H;
		set_offsetx(win, get_relx(x), 0);
		set_offsety(win, get_rely(y), 0);
	}
}
