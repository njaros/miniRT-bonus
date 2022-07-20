/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:33:32 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/11 09:56:38 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_vec_init(t_var *m)
{
	float	d;
	int		i;
	int		j;

	m->vec = ft_calloc(m->win.lenght * m->win.height, sizeof(t_vec));
	if (!m->vec)
		ft_error(m, 5);
	init_shared_data(m);
	d = m->win.lenght * (cos((m->ele.struc_c.fov / 2) * 2 * PI / 360)
			/ sin((m->ele.struc_c.fov / 2) * 2 * PI / 360));
	i = 0;
	while (i < m->win.height)
	{
		j = 0;
		while (j < m->win.lenght)
		{
			m->vec[i * m->win.lenght + j].x = d;
			m->vec[i * m->win.lenght + j].y = - (2 * j - m->win.lenght);
			m->vec[i * m->win.lenght + j].z = - (2 * i - m->win.height);
			ft_vec_normalization(&m->vec[i * m->win.lenght + j]);
			j++;
		}
		i++;
	}
}
