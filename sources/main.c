/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:19:22 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 20:19:24 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

t_win	*init_window(void)
{
	t_win	*win;

	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	win->m_p = mlx_init();
	win->w_p = mlx_new_window(win->m_p, W_W, W_H, "fractol 42 - gcaixeta");
	win->i_p = mlx_new_image(win->m_p, W_W, W_H);
	init_img(win);
	mlx_key_hook(win->w_p, key_hook, win);
	mlx_mouse_hook(win->w_p, mouse_hook, win);
	mlx_hook(win->w_p, 6, 0, motion_hook, win);
	mlx_loop(win->m_p);
	return (win);
}

int		main(void)
{
	t_win *win;

	if ((win = init_window()) == NULL)
		error();
	return (0);
}
