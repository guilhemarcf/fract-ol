/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:43:17 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 20:43:18 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	error(void)
{
	ft_putstr("Error: Something went wrong in the system.\n");
	ft_putstr("Don't be sad, it's not your fault\n");
	exit(0);
}

void	usage(void)
{
	ft_putstr("Usage: ./fract\'ol [fractal number1] [fractal number2]\n\n");
	ft_putstr("You can choose between:\n1 - Mandelbrot Set\n");
	ft_putstr("2 - Julia Set\n3 - Original Mandelbar (Tricorn Set)\n");
	ft_putstr("4 - Modified Mandelbar\n5 - Burning Ship Set\n");
	ft_putstr("You can view one or two fractals at a time.\n");
	exit(0);
}

void	print_instr(t_win *win)
{
	mlx_string_put(win->m_p, win->w_p, W_W / 15, W_H / 15, 0xFFFFFF,
		"\"ESC\" -> exit | \"A\" and \"Z\" -> zooming factor");
	mlx_string_put(win->m_p, win->w_p, W_W / 15, W_H / 15 + 20, 0xFFFFFF,
		"\"S\", \"D\", \"F\", \"X\", \"C\", \"V\" -> RGB");
	mlx_string_put(win->m_p, win->w_p, W_W / 15, W_H / 15 + 40, 0xFFFFFF,
		"\"G\", \"H\" -> color palette | \"J\", \"K\" -> iterations");
	mlx_string_put(win->m_p, win->w_p, W_W / 15, W_H / 15 + 60, 0xFFFFFF,
		"\"N\", \"M\" -> fractals | \"-\", \"=\" -> \"heads\"");
	mlx_string_put(win->m_p, win->w_p, W_W / 15, W_H / 15 + 80, 0xFFFFFF,
		"\"R\" -> reset all | \"E\" -> enable julia set");
}