/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:19:22 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 20:19:24 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

t_win	*set_window(void)
{
	t_win	*newin;

	if ((newin = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	else
		return (newin);
}

t_win	*init_window(int fracnum)
{
	t_win	*win;

	if ((win = set_window()) == NULL)
		return (NULL);
	win->m_p = mlx_init();
	win->w_p = mlx_new_window(win->m_p, W_W, W_H, "fractol 42 - gcaixeta");
	win->i_p = mlx_new_image(win->m_p, W_W, W_H);
	init_img(win, fracnum);
	mlx_key_hook(win->w_p, key_hook, win);
	mlx_hook(win->w_p, 6, 0, motion_hook, win);
	mlx_hook(win->w_p, 4, 0, mouse_press, win);
	mlx_hook(win->w_p, 5, 0, mouse_release, win);
	mlx_loop(win->m_p);
	return (win);
}

/*
** This functions sets the basic info needed to deal with the image in the
** very beginning of the manipulation.
*/

void		init_img(t_win *win, int fracnum)
{
	win->bpp = 32;
	win->size_line = win->bpp * W_W;
	win->endian = 1;
	win->offx = 0.0;
	win->offy = 0.0;
	win->fract = fracnum - 1;
	win->fract_beckup = win->fract;
	win->mode = 0;
	win->iters = 50;
	win->zoom = 10;
	win->mandelheads = 1;
	win->julia_enable = 1;
	win->move_screen = 0;
	win->odd_read = 0;
	win->color_pal = 0;
	win->red_incr = 8;
	win->green_incr = 8;
	win->blue_incr = 8;
	win->scaley = 3.5;
	win->scalex = (win->scaley * W_W) / (double)W_H;
	win->image = mlx_get_data_addr(win->i_p, &(win->bpp),
								&(win->size_line), &(win->endian));
	plot_image(win);
}

int		main(int ac, char **av)
{
	t_win	*win;
	int		fracnum;

	(void)av;
	if (ac == 2)
	{
		fracnum = ft_atoi(av[1]);
		if (fracnum < 1 || fracnum > 5)
			usage();
		if ((win = init_window(fracnum)) == NULL)
			error();
	}
	else
		usage();
	return (0);
}
