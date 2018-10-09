/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:38:35 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/10/06 19:38:36 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

/*
** This function effectively plots the mandelbrot set
*/

int		get_iterations(t_win *win, int i, int j)
{
	int	ite;

	if (win->fract == 0)
		ite = iterate_mandel(win->offx + app_sclx(j - (W_W / 2), win),
						win->offy + app_scly(i - (W_H / 2), win), win);
	else if (win->fract == 1)
		ite = iterate_julia(win->offx + app_sclx(j - (W_W / 2), win),
						win->offy + app_scly(i - (W_H / 2), win), win);
	else if (win->fract == 2)
		ite = iterate_tricorn1(win->offx + app_sclx(j - (W_W / 2), win),
						win->offy + app_scly(i - (W_H / 2), win), win);
	else if (win->fract == 3)
		ite = iterate_tricorn2(win->offx + app_sclx(j - (W_W / 2), win),
						win->offy + app_scly(i - (W_H / 2), win), win);
	else if (win->fract == 4)
		ite = iterate_ship(win->offx + app_sclx(j - (W_W / 2), win),
						win->offy + app_scly(i - (W_H / 2), win), win);
	else
		ite = 1;
	return (ite);
}

void	*work_thread(void *taux)
{
	int			j;
	int			ite;
	t_tx		*tx;

	tx = (t_tx *)taux;
	j = -1;
	while (++j < W_W)
	{
		ite = get_iterations(tx->win, tx->win->i + tx->id, j);
		if (tx->win->color_pal == 0)
			put_pixel_img(tx->win, tx->win->i + tx->id, j,
										set_color1(ite, tx->win));
		else if (tx->win->color_pal == 1)
			put_pixel_img(tx->win, tx->win->i + tx->id, j,
										set_color2(ite, tx->win));
		else if (tx->win->color_pal == 2)
			put_pixel_img(tx->win, tx->win->i + tx->id, j,
										set_color3(ite, tx->win));
		else if (tx->win->color_pal == 3)
			put_pixel_img(tx->win, tx->win->i + tx->id, j,
										set_color4(ite, tx->win));
	}
	return (NULL);
}

int		plot_image(t_win *win)
{
	int			i;
	int			t;
	t_tx		tx[THREADS];
	pthread_t	pt[THREADS];
	
	i = 0;
	while (i < W_H - THREADS)
	{
		t = -1;
		win->i = i;
		while(++t < THREADS)
		{
			tx[t].win = win;
			tx[t].id = t;
			pthread_create(&pt[t], NULL, work_thread, (void *)&tx[t]);
		}
		t = -1;
		while(++t < THREADS)
			pthread_join(pt[t], NULL);
		i += THREADS;
	}
	mlx_put_image_to_window(win->m_p, win->w_p, win->i_p, 0, 0);
	print_instr(win);
	return (1);
}

