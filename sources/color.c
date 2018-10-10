/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:37:09 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/23 17:37:11 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

/*
** This function scales the iterations for the pixel over the possible
** iterations and multiplies it by a color increment stored in the win struct.
** The result is the RGB value, which is passed to an int, and then returned.
*/

int				set_color1(int ite, t_win *win)
{
	int		hexcolor;
	int		red;
	int		green;
	int		blue;

	if (ite < win->iters)
	{
		red = (ite / (double)win->iters) * (win->red_incr * 32 - 1);
		green = (ite / (double)win->iters) * (win->green_incr * 32 - 1);
		blue = (ite / (double)win->iters) * (win->blue_incr * 32 - 1);
		hexcolor = red << 16 | green << 8 | blue;
		return (hexcolor);
	}
	else
		return (0xFFFFFF);
}

/*
** This function colors the fractals by shifting bits according to the number
** of iterations for the pixel. Hacky and cool.
*/

int				set_color2(int ite, t_win *win)
{
	if (ite < win->iters)
		return ((0x0000FF % (int)win->iters) << ite);
	else
		return (0xFFFFFF);
}

/*
** This is a very hacky way of gettin psychedelic colors, just scaling the
** equivalent of white to the number of iterations over the total iterations.
** since the bits in the white color represent RGB in a different way that
** they represent a number, the result is very cool and unpredictable.
** This one is the inverse of the function below.
*/

int				set_color3(int ite, t_win *win)
{
	int		hexcolor;

	(void)win;
	if (ite < win->iters)
	{
		hexcolor = 16777216 * (ite / (double)win->iters);
		return (hexcolor);
	}
	else
		return (0xFFFFFF);
}

/*
** This is a very hacky way of gettin psychedelic colors, just scaling the
** equivalent of white to the number of iterations over the total iterations.
** since the bits in the white color represent RGB in a different way that
** they represent a number, the result is very cool and unpredictable.
*/

int				set_color4(int ite, t_win *win)
{
	int		hexcolor;

	(void)win;
	if (ite < win->iters)
	{
		hexcolor = 16777216 * ((win->iters - ite) / (double)win->iters);
		return (hexcolor);
	}
	else
		return (0xFFFFFF);
}
