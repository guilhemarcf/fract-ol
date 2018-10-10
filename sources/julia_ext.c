/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:55:39 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/10/06 20:55:39 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

/*
** This function enables the acquisition of data points for the generation of
** the julia set. I needed to stop the program from acquiring data points so
** I could zoom in th julia set and enjoy its endless crazy forms.
*/

void	able_julia(t_win *win)
{
	if (win->julia_enable == 0)
		win->julia_enable = 1;
	else
		win->julia_enable = 0;
}

/*
** This function simply applies the scale of the current image to the x y
** mouse coordinates, so they can be used to render the julia set in a
** continous way.
*/

void	follow_julia(int x, int y, t_win *win)
{
	if (win->julia_enable)
	{
		win->p_julia.x = app_sclx(x - W_W / 2, win);
		win->p_julia.y = app_scly(y - W_H / 2, win);
	}
}
