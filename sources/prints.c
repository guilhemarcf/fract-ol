/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:43:17 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 20:43:18 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	error(void)
{
	ft_putendl("something was wrong with the input.");
	exit(0);
}

void	plot_line(t_win *win)
{
	int 	dx, dy, steps, i;
	float	xincr, yincr, x1, x2, y1, y2;

	x1 = (float)win->x1;
	x2 = (float)win->x2;
	y1 = (float)win->y1;
	y2 = (float)win->y2;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xincr = (float) dx / (float)steps;
	yincr = (float) dy / (float)steps;
	i = -1;
	while (++i <= steps)
	{
		x1 = x1 + xincr;
		y1 = y1 + yincr;
		mlx_pixel_put(win->m_p, win->w_p, round(x1), round(y1), 0xFFFFFF);
	}
}
