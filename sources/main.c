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

/*
** This function is called only once, to initialize the parameter of win,
** the "window" struct I use to control the behavior of the whole program.
** It stores the number of the fractal I wanted first, so when I reset the
** image, it will always go back to the original fractal.
*/

void	init_img(t_win *win, int fracnum)
{
	win->bpp = 32;
	win->size_line = win->bpp * W_W;
	win->endian = 1;
	win->offx = 0.0;
	win->offy = 0.0;
	win->fract = fracnum - 1;
	win->fract_backup = win->fract;
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

/*
** This function is where the magic happens. It gets a new win struct, which
** will contain all the variables I will use to regulate and make viable the
** functioning of the program, and contains all the loops and event listeners.
** All the subsequent actions wil be triggered by the keys and mouse, which
** can be found in their respective files.
*/

t_win	*init_window(int fracnum)
{
	t_win	*win;

	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	win->m_p = mlx_init();
	win->w_p = mlx_new_window(win->m_p, W_W, W_H, "fractol 42 - gcaixeta");
	win->i_p = mlx_new_image(win->m_p, W_W, W_H);
	init_img(win, fracnum);
	mlx_key_hook(win->w_p, key_hook, win);
	mlx_hook(win->w_p, 6, 0, motion_hook, win);
	mlx_hook(win->w_p, 4, 0, mouse_press, win);
	mlx_hook(win->w_p, 5, 0, mouse_release, win);
	mlx_loop_hook(win->m_p, &plot_image, win);
	mlx_loop(win->m_p);
	return (win);
}

/*
** The main checks for the single argument that is accepts, if there is
** a mistake, prints the proper usage, but if that's ok, initializes the
** process of opening the window.
*/

int		main(int ac, char **av)
{
	int			fracnum1;
	t_win		*win;

	if (ac == 2)
	{
		fracnum1 = ft_atoi(av[1]);
		if (fracnum1 < 1 || fracnum1 > 5)
			usage();
		win = init_window(fracnum1);
	}
	else
		usage();
	return (0);
}
