/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:22:32 by njaros            #+#    #+#             */
/*   Updated: 2022/07/01 13:55:26 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_inter_c(t_inter *inter, t_cy c)
{
	if (inter->cyl_touch == 4)
		inter->normal = crea_vector(inter->point, \
		set_pointline(cy_line(c), \
		distance_projection(cy_line(c), inter->point)));
	else
		inter->normal = crea_vector(set_pointline(cy_line(c), \
		distance_projection(cy_line(c), \
		inter->point)), inter->point);
	ft_vec_normalization(&inter->normal);
	inter->object = CYLINDER;
}

bool	pcy(t_inter *inter, int touch, float dist, bool consider)
{
	inter->cyl_touch = touch;
	if (consider)
		inter->dist = dist;
	return (1);
}

bool	cyl_plan_dist(t_line l, t_cy c, float *d_pu, float *d_pd)
{
	float	secure;
	t_line	l_up;
	t_line	l_down;

	secure = ft_dot_product(l.dir, c.plan_up.vec);
	if (secure)
	{
		*d_pu = plan_dist(l, c.plan_up);
		*d_pd = plan_dist(l, c.plan_down);
		return (1);
	}
	l_up.point = c.plan_up.coord;
	l_up.dir = l.dir;
	l_down.point = c.plan_down.coord;
	l_down.dir = l.dir;
	*d_pu = paralel_dist(l_up, l);
	*d_pd = paralel_dist(l_down, l);
	return (0);
}

bool	min_mu(t_inter *i, t_line l, t_cy cy, float mu)
{
	float	d_pu;
	float	d_pd;

	i->dist -= mu;
	if (!cyl_plan_dist(l, cy, &d_pu, &d_pd)
		&& (side_plan(cy.plan_up, l.point) ^ side_plan(cy.plan_down, l.point)))
		return (1);
	if ((d_pu < d_pd && d_pd < i->dist) \
		|| (d_pd < d_pu && d_pu < i->dist))
		return (1);
	else if ((((d_pu < i->dist) && (i->dist < d_pd)) \
		|| ((d_pd < i->dist) && (i->dist < d_pu)) \
		|| (d_pd == d_pu && d_pd > i->dist)) \
		&& pcy(i, 1, 0, 0))
		set_ex_c(i, l, cy);
	else if (i->dist < d_pu && d_pu < d_pd && d_pu < (i->dist + (2 * mu)) \
		&& pcy(i, 2, d_pu, 1))
		set_ex_c(i, l, cy);
	else if (i->dist < d_pd && d_pd < (i->dist + (2 * mu))
		&& pcy(i, 3, d_pd, 1))
		set_ex_c(i, l, cy);
	return (1);
}

bool	plus_mu(t_inter *i, t_line l, t_cy cy, float mu)
{
	float	d_pu;
	float	d_pd;

	i->dist += mu;
	d_pu = plan_dist(l, cy.plan_up);
	d_pd = plan_dist(l, cy.plan_down);
	if (d_pu > 0 && d_pd > 0 && d_pu < d_pd && i->dist > d_pu
		&& pcy(i, 2, d_pu, 1))
		set_ex_c(i, l, cy);
	else if (d_pu > 0 && d_pd > 0 && i->dist > d_pd && pcy(i, 3, d_pd, 1))
		set_ex_c(i, l, cy);
	else if (((d_pu > 0 && d_pd < 0 && i->dist < d_pu) || (d_pu < 0 && d_pd > 0
				&& i->dist < d_pd)) && pcy(i, 4, 0, 0))
		set_ex_c(i, l, cy);
	else if (d_pu > 0 && d_pd < 0 && i->dist > d_pu && pcy(i, 2, d_pu, 1))
		set_ex_c(i, l, cy);
	else if (d_pu < 0 && d_pd > 0 && i->dist > d_pd && pcy(i, 3, d_pd, 1))
		set_ex_c(i, l, cy);
	return (1);
}
