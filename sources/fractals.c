/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:37:18 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/10/06 19:37:19 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

/*
** The math formula to generate the mandelbrot set fractal
*/

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
	return (i);
}

/*
** The math formula to generate the julia set fractal
*/

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
	return (i);
}

/*
** The math formula to generate the original tricorn fractal
*/

int			iterate_tricorn1(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	aux;
	t_complex	z_itr;
	int			i;

	z = get_complex(&z, re_base, im_base);
	z_itr = get_complex(&z_itr, re_base, im_base);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		aux = pow_complex(z, win->mandelheads + 1);
		z.re = aux.re + z_itr.re;
		z.im = z_itr.im - aux.im;
	}
	return (i);
}

/*
** The math formula to generate the modified tricorn fractal
*/

int			iterate_tricorn2(double re_base, double im_base, t_win *win)
{
	t_complex	z;
	t_complex	aux;
	t_complex	z_itr;
	int			i;

	z = get_complex(&z, re_base, im_base);
	z_itr = get_complex(&z_itr, re_base, im_base);
	i = -1;
	while (++i < win->iters && module_smaller_than_2(z))
	{
		aux = pow_complex(z, win->mandelheads + 1);
		z.re = aux.re + z.re;
		z.im = z.im - aux.im;
	}
	return (i);
}

/*
** The math formula to generate the burning ship fractal
*/

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
	return (i);
}
