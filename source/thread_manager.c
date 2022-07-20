/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:25:31 by njaros            #+#    #+#             */
/*   Updated: 2022/07/20 16:25:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_cpu_task(t_pixel_task *pxt, int h, int l)
{
	long int	lenght;
	long int	idx;

	lenght = h * l;
	idx = 0;
	while (idx < lenght)
	{
		pxt[idx].transit = 0;
		pxt[idx].i = idx / l;
		pxt[idx].j = idx - (pxt[idx].i * l);
		pthread_mutex_init(&pxt[idx].check, NULL);
		idx++;
	}
}

void	thread_launcher(t_var *m, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_create(&m->cpu[i], NULL, thread_routine, &m->to_do_list);
		i++;
	}
}

void	init_shared_data(t_var *m)
{
	unsigned int	size;

	size = m->win.height * m->win.lenght;
	m->nb_cpu = sysconf(_SC_NPROCESSORS_ONLN);
	m->cpu = malloc(sizeof(pthread_t) * m->nb_cpu);
	m->to_do_list.to_do = malloc(sizeof(t_pixel_task) * size);
	m->to_do_list.m = m;
	m->to_do_list.work_finished = 0;
	m->to_do_list.rdy_count = 0;
	m->size = size;
	pthread_mutex_init(&m->to_do_list.sleep, NULL);
	pthread_mutex_init(&m->to_do_list.work, NULL);
	pthread_mutex_lock(&m->to_do_list.sleep);
	init_cpu_task(m->to_do_list.to_do, m->win.height, m->win.lenght);
	thread_launcher(m, m->nb_cpu);
	dprintf(1, "nb of cpu %d\n", m->nb_cpu);
}

void	thread_manager(t_var *m)
{
	pthread_mutex_unlock(&m->to_do_list.sleep);
	while (1)
	{
		pthread_mutex_lock(&m->to_do_list.sleep);
		if (m->to_do_list.rdy_count == m->nb_cpu)
		{
			m->to_do_list.rdy_count = 0;
			break ;
		}
		pthread_mutex_unlock(&m->to_do_list.sleep);
	}
	while (1)
	{
		pthread_mutex_lock(&m->to_do_list.work);
		if (m->to_do_list.work_finished)
		{
			m->to_do_list.work_finished = 0;
			pthread_mutex_unlock(&m->to_do_list.work);
			break ;
		}
		pthread_mutex_unlock(&m->to_do_list.work);
	}
}
