/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:05:48 by njaros            #+#    #+#             */
/*   Updated: 2022/07/01 15:09:07 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	side_plan(t_pl plan, t_coord point)
{
	if (ft_dot_product(plan.vec, crea_vector(point, plan.coord)) > 0)
		return (1);
	return (0);
}

bool	secure_glitch_plan(t_pl plan, t_coord point)
{
	float	side;

	side = ft_dot_product(plan.vec, crea_vector(point, plan.coord));
	if (side > -0.0001 && side < 0.0001)
		return (1);
	return (0);
}

bool	check_light_inter_plan(t_var *m, t_line l, float coef)
{
	int		n;
	t_inter	tool;
	t_pl	p;

	n = m->ele.pl;
	while (n)
	{
		p = m->ele.struc_pl[n - 1];
		if (secure_glitch_plan(p, l.point) || (side_plan
				(p, m->ele.struc_c.coord) ^ side_plan(p, l.point)))
			return (1);
		tool = inter_plan(l, p);
		if (tool.exist && (tool.dist - coef < -0.0001))
			return (1);
		n--;
	}
	return (0);
}

bool	in_sphere(t_sp s, t_coord point)
{
	t_vec	vec;
	float	dist;

	vec = crea_vector(s.coord, point);
	dist = (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)
		- ((s.diam * s.diam) / 4);
	if (dist < 0)
		return (1);
	return (0);
}

bool	secure_glitch_sphere(t_sp s, t_coord point)
{
	t_vec	vec;
	float	dist;

	vec = crea_vector(s.coord, point);
	dist = (vec.x * vec.x + vec.y * vec.y + vec.z
			* vec.z) - ((s.diam * s.diam) / 4);
	if (dist > -0.0001 && dist < 0.0001)
		return (1);
	return (0);
}
