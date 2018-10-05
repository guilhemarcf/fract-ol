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

int		get_iterations(t_win *win, int i, int j)
{
	int	ite;

	if (win->fract == 0)
		ite = iterate_mandel(win->offx + app_sclx(j - (W_W / 2), win),
									win->offy + app_scly(i - (W_H / 2), win),
																win->iters);
	else if (win->fract == 1)
		ite = iterate_julia(win->offx + app_sclx(j - (W_W / 2), win),
									win->offy + app_scly(i - (W_H / 2), win),
															win->iters, win);
	else
		ite = 1;
	return (ite);
}

void	plot_image(t_win *win)
{
	int		i;
	int		j;
	int		ite;

	i = -1;
	while (++i < W_H)
	{
		j = -1;
		while (++j < W_W)
		{
			ite = get_iterations(win, i, j);
			if (win->color_pal == 0)
				put_pixel_img(win, i, j, set_color1(ite, win));
			else if (win->color_pal == 1)
				put_pixel_img(win, i, j, set_color2(ite, win));
			else if (win->color_pal == 2)
				put_pixel_img(win, i, j, set_color3(ite, win));
			else if (win->color_pal == 3)
				put_pixel_img(win, i, j, set_color4(ite, win));
		}
	}
	mlx_put_image_to_window(win->m_p, win->w_p, win->i_p, 0, 0);
}
