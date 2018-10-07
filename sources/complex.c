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
