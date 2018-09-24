/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:20:27 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 21:20:28 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int		motion_hook(int x, int y, t_win *win)
{
	(void)y;
	set_gradient(win);
	mlx_put_image_to_window(win->m_p, win->w_p, win->i_p, 0, 0);
	if (x >= 0 && x <= W_W / 3)
		win->reg1 = 0;
	else
		win->reg1 = 1;
	if (x > W_W / 3 && x <= (2 * W_W) / 3)
		win->reg2 = 0;
	else
		win->reg2 = 1;
	if (x > (2 * W_W) / 3 && x <= W_W)
		win->reg3 = 0;
	else
		win->reg3 = 1;
	return (1);
}

int		mouse_hook(int button, int x, int y, t_win *win)
{
	ft_putnbr(button);
	(void)win;
	(void)x;
	(void)y;
	set_mwparam(button, win);
	return (1);
}

void	set_mwparam(int button, t_win *win)
{
	if (button == 4)
		win->mwparam = win->mwparam * 1.05;
	else if (button == 5)
		win->mwparam = win->mwparam * 0.97;
}