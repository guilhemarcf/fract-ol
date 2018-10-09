/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:54:55 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/10/09 13:54:56 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	*new_main_thread(void *vargp)
{
	t_win	*win;

	win = init_window(*(int *)vargp);
	return (NULL);
}

void	initialize_prog_2_par(int fracnum1, int fracnum2)
{
	pthread_t	tid1;
	pthread_t	tid2;

	pthread_create(&tid1, NULL, new_main_thread, (void *)&fracnum1);
	pthread_create(&tid2, NULL, new_main_thread, (void *)&fracnum2);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_exit(NULL);
}

void	initialize_prog_1_par(int fracnum1)
{
	//pthread_t	tid1;
	t_win	*win;

	win = init_window(fracnum1);
	(void)fracnum1;
	//pthread_create(&tid1, NULL, new_thread, (void *)&fracnum1);
	//pthread_join(tid1, NULL);
	//pthread_exit(NULL);
}
