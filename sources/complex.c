/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 00:20:52 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/24 00:20:53 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		squarefy_complex(double re_base, double im_base,
										double *re_res, double *im_res)
{
	*re_res = (re_base * re_base) - (im_base * im_base);
	*im_res = 2 * re_base * im_base;
}

double		module_complex(double re, double im)
{
	return (sqrt((re * re) + (im * im)));
}

/*
**
*/

int			iterate_mandel(double re_base, double im_base)
{
	double	x;
	double	y;
	double	re_itr;
	double	im_itr;
	int		i;

	x = 0;
	y = 0;
	re_itr = re_base;
	im_itr = im_base;
	i = -1;
	while (++i < ITERS && module_complex(x, y) < 2.0)
	{
		squarefy_complex(x, y, &re_itr, &im_itr);
		x = re_itr + re_base;
		y = im_itr + im_base;
	}
	if (i < ITERS)
		return (i);
	else
		return (0);
}

int			iterate_julia(double re_base, double im_base)
{
	double	x;
	double	y;
	double	re_itr;
	double	im_itr;
	int		i;

	x = 0;
	y = 0;
	re_itr = re_base;
	im_itr = im_base;
	i = -1;
	while (++i < ITERS && module_complex(x, y) < 2.0)
	{
		squarefy_complex(x, y, &re_itr, &im_itr);
		x = re_itr + re_base;
		y = im_itr + im_base;
	}
	if (i < ITERS)
		return (i);
	else
		return (0);
}
