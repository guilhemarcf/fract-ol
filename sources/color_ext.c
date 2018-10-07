/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:52:32 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/10/06 20:52:33 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	change_color_incr_up(t_win *win)
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

void	change_color_incr_down(t_win *win)
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
