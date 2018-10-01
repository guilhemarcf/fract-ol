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
	ft_putendl("something went wrong");
	exit(0);
}

/*
** This function effectively plots the mandelbrot set
*/

void	plot_image(t_win *win)
{
	int		i;
	int		j;
	int		color;
	double	amp;

	i = -1;
	while (++i < W_H)
	{
		j = -1;
		while (++j < W_W)
		{
			amp = iterate_mandel(win->offx + app_sclx(j - (W_W / 2), win),
									win->offy + app_scly(i - (W_H / 2), win));
			color = set_color(amp, win);
			put_pixel_img(win, i, j, color);
		}
	}
	mlx_put_image_to_window(win->m_p, win->w_p, win->i_p, 0, 0);
}
