/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:01:11 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/22 21:01:12 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int		key_hook(int keycode, t_win *win)
{
	win->keycode = keycode;
	act_on_key(win);
	return (keycode);
}

void	act_on_key(t_win *win)
{
	ft_putnbr(win->keycode);
	ft_putchar(' ');
	if (win->keycode == 53)
		exit(0);
}