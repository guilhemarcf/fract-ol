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
	win->mwparam = 1;
	win->reg1 = 1;
	win->reg2 = 1;
	win->reg3 = 1;
	set_color_incrs(win);
}

/*
** This is my current pixel put function. It takes advantage that I set the
** bpp to 32, making a perfect int every 4 chars of the image, so all I had
** to do was treat the image like an array of integers and insert the int
** for the color to ever int position.
*/

void		put_pixel_img(char *image, int x, int y, int color)
{
	int		*img;

	img = (int *)image;
	img[(x * W_W) + y] = color;
}

/*
** This function was just an experiment to see if I could make the colors
** work. Now that I discovered I'm able to have a gradient, I'll try to
** regulate it with the mouse wheel changing a parameter.
*/

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
			put_pixel_img(win->image, i, j, set_color(win, i, j));
	}
}
