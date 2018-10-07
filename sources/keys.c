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

int		key_hook(int keycode, t_win *win)
{
	win->keycode = keycode;
	act_on_key(win);
	return (keycode);
}

void	able_julia(t_win *win)
{
	if (win->julia_enable == 0)
		win->julia_enable = 1;
	else
		win->julia_enable = 0;
}

void	change_mandelheads(t_win *win)
{
	if (win->keycode == 27)
	{
		if (win->mandelheads > 0)
			win->mandelheads--;
		else
			win->mandelheads = 12;
	}
	else if (win->keycode == 24)
	{
		if (win->mandelheads < 12)
			win->mandelheads++;
		else
			win->mandelheads = 0;
	}
}

void	act_on_key(t_win *win)
{
	ft_putnbr(win->keycode);
	ft_putchar(' ');
	if (win->keycode == 53)
		exit(0);
	else if (win->keycode == 14)
		able_julia(win);
	else if (win->keycode == 45 || win->keycode == 46)
		change_fract(win);
	else if (win->keycode == 24 || win->keycode == 27)
		change_mandelheads(win);
	else if (win->keycode >= 1 && win->keycode <= 3)
		change_color_incr1(win);
	else if (win->keycode >= 7 && win->keycode <= 9)
		change_color_incr2(win);
	else if (win->keycode >= 123 && win->keycode <= 126)
		change_offset_keys(win);
	else if (win->keycode >= 12 && win->keycode <= 17)
		reset_img(win);
	else if (win->keycode == 4 || win->keycode == 5)
		change_color_pal(win);
	else if (win->keycode == 0 || win->keycode == 6)
		change_zoom(win);
	else if (win->keycode == 38 || win->keycode == 40)
		change_iters(win);
	plot_image(win);
}

void	change_iters(t_win *win)
{
	if (win->keycode == 38 && (win->iters < 1000))
		win->iters *= 1.025;
	else if (win->keycode == 40 && (win->iters > 5))
		win->iters *= 0.97560975609;
}

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

void	change_fract(t_win *win)
{
	if (win->keycode == 45)
	{
		if (win->fract > 0)
			win->fract--;
		else
			win->fract = 4;
	}
	else if (win->keycode == 46)
	{
		if (win->fract < 4)
			win->fract++;
		else
			win->fract = 0;
	}
}

void	change_color_incr1(t_win *win)
{
	if (win->keycode == 1)
	{
		if (win->red_incr < 8)
			win->red_incr++;
		else
			win->red_incr = 1;
	}
	else if (win->keycode == 2)
	{
		if (win->green_incr < 8)
			win->green_incr++;
		else
			win->green_incr = 1;
	}
	else if (win->keycode == 3)
	{
		if (win->blue_incr < 8)
			win->blue_incr++;
		else
			win->blue_incr = 1;
	}
}

void	change_color_incr2(t_win *win)
{
	if (win->keycode == 7)
	{
		if (win->red_incr > 1)
			win->red_incr--;
		else
			win->red_incr = 8;
	}
	else if (win->keycode == 8)
	{
		if (win->green_incr > 1)
			win->green_incr--;
		else
			win->green_incr = 8;
	}
	else if (win->keycode == 9)
	{
		if (win->blue_incr > 1)
			win->blue_incr--;
		else
			win->blue_incr = 8;
	}
}

