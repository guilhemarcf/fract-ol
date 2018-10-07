/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:58:33 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/23 16:58:34 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

/*
** This functions sets the basic info needed to deal with the image in the
** very beginning of the manipulation.
*/

void		init_img(t_win *win)
{
	win->bpp = 32;
	win->size_line = win->bpp * W_W;
	win->endian = 1;
	win->offx = 0.0;
	win->offy = 0.0;
	win->fract = 0;
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

void		reset_img(t_win *win)
{
	win->offx = 0.0;
	win->offy = 0.0;
	win->fract = 0;
	win->mode = 0;
	win->iters = 50;
	win->zoom = 10;
	win->julia_enable = 1;
	win->mandelheads = 1;
	win->move_screen = 0;
	win->odd_read = 0;
	win->color_pal = 0;
	win->red_incr = 8;
	win->green_incr = 8;
	win->blue_incr = 8;
	win->scaley = 3.5;
	win->scalex = (win->scaley * W_W) / (double)W_H;
	plot_image(win);
}


/*
** This is my current pixel put function. It takes advantage that I set the
** bpp to 32, making a perfect int every 4 chars of the image, so all I had
** to do was treat the image like an array of integers and insert the int
** for the color to ever int position.
*/

void		put_pixel_img(t_win *win, int y, int x, int color)
{
	int		*img;

	img = (int *)(win->image);
	img[(y * W_W) + x] = color;
}


/*
** This function was just an experiment to see if I could make the colors
** work. Now that I discovered I'm able to have a gradient, I'll try to
** regulate it with the mouse wheel changing a parameter.
*/
/*
void		set_gradient(t_win *win)
{
	int		i;
	int		j;
	int		*img;
	
	win->image = mlx_get_data_addr(win->i_p, &(win->bpp),
								&(win->size_line), &(win->endian));
	img = (int *)(win->image);
	i = -1;
	while (++i < W_H)
	{
		j = -1;
		while (++j < W_W)
			put_pixel_img(win->image, i, j,
							set_color(win, i - W_H / 2, j - W_W / 2));
	}
}
*/