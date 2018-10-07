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

void	able_julia(t_win *win)
{
	if (win->julia_enable == 0)
		win->julia_enable = 1;
	else
		win->julia_enable = 0;
}

void	follow_julia(int x, int y, t_win *win)
{
	if (win->julia_enable)
	{
		win->p_julia.x = app_sclx(x - W_W / 2, win);
		win->p_julia.y = app_scly(y - W_H / 2, win);
		plot_image(win);
	}
}
