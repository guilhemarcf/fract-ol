/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:46:17 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/24 01:46:17 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

double		app_sclx(int j, t_win *win)
{
	return ((j * win->scalex) / (double)W_W);
}

double		app_scly(int i, t_win *win)
{
	return ((i  * win->scaley) / (double)W_H);
}


//stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c#