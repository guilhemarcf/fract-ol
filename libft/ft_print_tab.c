/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:08:34 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/08/03 15:08:35 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putnbr(i);
		ft_putchar('\n');
		ft_putendl(s[i]);
		ft_putchar('\n');
		i++;
	}
}
