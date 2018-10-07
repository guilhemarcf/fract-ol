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

t_complex	multiply_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.re = z1.re * z2.re - z1.im * z2.im;
	result.im = z1.re * z2.im + z2.re * z1.im;
	return (result);
}

t_complex	pow_complex(t_complex z, int power)
{
	int			i;
	t_complex	result;

	result = z;
	i = 1;
	while (i < power)
	{
		result = multiply_complex(result, z);
		i++;
	}
	return (result);
}


t_complex	sum_complex(t_complex z1, t_complex z2)
{
	z1.re = z1.re + z2.re;
	z1.im = z1.im + z2.im;
	return (z1);
}

int			module_smaller_than_2(t_complex z)
{
	if (z.re * z.re + z.im * z.im > 4.0)
		return (0);
	else
		return (1);
}

t_complex	get_complex(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
	return (*z);
}

int			iterate_mandel(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	z_itr;
	int			i;

	z = get_complex(&z, 0, 0);
	z_itr = get_complex(&z_itr, re_base, im_base);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		z = sum_complex(pow_complex(z, win->mandelheads + 1), z_itr);
	}
	if (i < win->iters)
		return (i);
	else
		return (0);
}

int			iterate_julia(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	z_itr;
	int			i;

	z = get_complex(&z, re_base, im_base);
	z_itr = get_complex(&z_itr, win->p_julia.x, win->p_julia.y);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		z = sum_complex(pow_complex(z, win->mandelheads + 1), z_itr);
	}
	if (i < win->iters)
		return (i);
	else
		return (0);
}

int			iterate_tricorn1(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	z_itr;
	double		re_temp;
	int			i;

	z = get_complex(&z, re_base, im_base);
	z_itr = get_complex(&z_itr, re_base, im_base);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		re_temp = z.re * z.re - z.im * z.im + z.re;
		z.im = z.im - 2 * z.re * z.im;
		z.re = re_temp;
	}
	if (i < win->iters)
		return (i);
	else
		return (0);
}

int			iterate_tricorn2(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	z_itr;
	double		re_temp;
	int			i;

	z = get_complex(&z, re_base, im_base);
	z_itr = get_complex(&z_itr, re_base, im_base);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		re_temp = z.re * z.re - z.im * z.im + z_itr.re;
		z.im = z_itr.im - 2 * z.re * z.im;
		z.re = re_temp;
	}
	if (i < win->iters)
		return (i);
	else
		return (0);
}


int			iterate_ship(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	z_itr;
	double		re_temp;
	int			i;

	z = get_complex(&z, re_base, im_base);
	z_itr = get_complex(&z_itr, re_base, im_base);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		re_temp = z.re * z.re - z.im * z.im + z_itr.re;
		z.im = fabs(2 * z.im * z.re) + z_itr.im;
		z.re = fabs(re_temp);
	}
	if (i < win->iters)
		return (i);
	else
		return (0);
}

