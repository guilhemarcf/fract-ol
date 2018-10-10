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

/*
** This function contains the algorithm for interpreting the multiplication
** of real numbers as complex numbers. It multiplies real numbers in a way
** that the result can be correctly interpreted as a complex product.
*/

t_complex	multiply_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.re = z1.re * z2.re - z1.im * z2.im;
	result.im = z1.re * z2.im + z2.re * z1.im;
	return (result);
}

/*
** Multiplies a complex number by itself power times.
*/

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

/*
** Returns a complex which is the result of the sum of two other complex
** numbers.
*/

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	z1.re = z1.re + z2.re;
	z1.im = z1.im + z2.im;
	return (z1);
}

/*
** If the module of the given complex is bigger than 2, return 0,
** otherwise, return 1.
*/

int			module_smaller_than_2(t_complex z)
{
	if (z.re * z.re + z.im * z.im > 4.0)
		return (0);
	else
		return (1);
}

/*
** This function passes by reference the values to a complex struct.
*/

t_complex	get_complex(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
	return (*z);
}
