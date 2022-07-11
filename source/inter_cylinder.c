/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:18:10 by njaros            #+#    #+#             */
/*   Updated: 2022/07/01 13:58:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_line	cy_line(t_cy c)
{
	t_line	l;

	l.dir = c.vec;
	l.point = c.coord;
	return (l);
}

bool	set_ex_c(t_inter *inter, t_line l, t_cy c)
{
	inter->exist = 1;
	inter->color = c.color;
	inter->point = set_pointline(l, inter->dist);
	if (inter->cyl_touch == 1 || inter->cyl_touch == 4)
		fill_inter_c(inter, c);
	else if (inter->cyl_touch == 2)
	{
		if (side_plan(c.plan_up, l.point))
			inter->normal = c.plan_down.vec;
		else
			inter->normal = c.plan_up.vec;
		inter->object = PLAN;
	}
	else if (inter->cyl_touch == 3)
	{
		if (side_plan(c.plan_down, l.point))
			inter->normal = c.plan_up.vec;
		else
			inter->normal = c.plan_down.vec;
		inter->object = PLAN;
	}
	return (1);
}

t_inter	inter_cylinder(t_line l, t_cy cy)
{
	t_inter	inter;
	float	d;
	float	mu;

	inter.exist = 0;
	d = lines_normal_segment(cy_line(cy), l, &inter);
	if (d >= (cy.diam * cy.diam) / 4)
		return (inter);
	d = sqrt (d);
	mu = ((cy.diam / 2) * sin(acos(d / (cy.diam / 2))))
		/ cos(asin(ft_dot_product(l.dir, cy.vec)));
	if (inter.dist - mu > 0 && min_mu(&inter, l, cy, mu))
		return (inter);
	if (inter.dist + mu > 0 && plus_mu(&inter, l, cy, mu))
		return (inter);
	return (inter);
}
