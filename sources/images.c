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
** This function is called everytime R is pressed, in order to bring the image
** to its original parameters.
*/

void		reset_img(t_win *win)
{
	win->offx = 0.0;
	win->offy = 0.0;
	win->fract = win->fract_backup;
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
** This function alters the power to which the complex numbers are elevated
** in the rendering of the fractals, causing some interesting effects.
** I called it mandelheads because it changes the number of "heads" of the
** mandelbrot set.
** The caller of this function is in the keys file.
*/

void		change_mandelheads(t_win *win)
{
	if (win->keycode == 27)
	{
		if (win->mandelheads > 0)
			win->mandelheads--;
		else
			win->mandelheads = 7;
	}
	else if (win->keycode == 24)
	{
		if (win->mandelheads < 7)
			win->mandelheads++;
		else
			win->mandelheads = 0;
	}
}

/*
** This function changes the amount of iterations that happen for each pixel,
** making it slower or faster, more or less detailed. The more iterations,
** the more one can zoom in the set.
** The caller of this function is in the keys file.
*/

void		change_iters(t_win *win)
{
	if (win->keycode == 38 && (win->iters < 1000))
		win->iters *= 1.025;
	else if (win->keycode == 40 && (win->iters > 5))
		win->iters *= 0.97560975609;
}

/*
** This function changes among the types of fractal that this program renders,
** and its caller is in the keys file.
*/

void		change_fract(t_win *win)
{
	if (win->keycode == 45)
	{
		if (win->fract > 0)
			win->fract--;
		else
			win->fract = 4;
	}
	else if (win->keycode == 46)
	{
		if (win->fract < 4)
			win->fract++;
		else
			win->fract = 0;
	}
}
