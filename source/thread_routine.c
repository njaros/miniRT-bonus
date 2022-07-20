/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:25:39 by njaros            #+#    #+#             */
/*   Updated: 2022/07/20 16:25:39 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	do_the_pixel(t_var *m, int i, int j)
{
	t_vec	tmp;

	ft_mat_vec(m->vec[i * m->win.lenght + j], m->mat_rot, &tmp);
	ft_pixel_put(m, i, j, tmp);
}

void	set_it_finished(t_var *m, t_shared *p)
{
	pthread_mutex_lock(&m->to_do_list.work);
	p->work_finished = 1;
	pthread_mutex_unlock(&m->to_do_list.work);
}

void	go_to_work(t_var *m, t_shared *p)
{
	unsigned int	idx;

	idx = 0;
	while (idx < m->size)
	{
		pthread_mutex_lock(&p->to_do[idx].check);
		if (!p->to_do[idx].transit++)
		{
			pthread_mutex_unlock(&p->to_do[idx].check);
			do_the_pixel(m, p->to_do[idx].i, p->to_do[idx].j);
		}
		else
		{
			if (p->to_do[idx].transit == m->nb_cpu)
			{
				p->to_do[idx].transit = 0;
				if (idx == m->size - 1)
					set_it_finished(m, p);
			}
			pthread_mutex_unlock(&p->to_do[idx].check);
		}
		idx++;
	}
}

void	*thread_routine(void *arg)
{
	t_shared	*p;
	t_var		*m;

	p = arg;
	m = p->m;
	while (1)
	{
		pthread_mutex_lock(&p->sleep);
		p->rdy_count++;
		pthread_mutex_unlock(&p->sleep);
		go_to_work(m, p);
	}
}
