/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:52:15 by njaros            #+#    #+#             */
/*   Updated: 2022/06/29 16:39:03 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_ex_p(t_inter *inter, t_line l, t_pl p)
{
	inter->exist = 1;
	inter->color = p.color;
	inter->point = set_pointline(l, inter->dist);
	if (ft_dot_product(crea_vector(l.point, inter->point), p.vec) < 0)
	{
		inter->normal.x = p.vec.x;
		inter->normal.y = p.vec.y;
		inter->normal.z = p.vec.z;
	}
	else
	{
		inter->normal.x = -p.vec.x;
		inter->normal.y = -p.vec.y;
		inter->normal.z = -p.vec.z;
	}
	inter->object = PLAN;
}

bool	set_ex_s(t_inter *inter, t_line l, t_sp s, float mu)
{
	inter->exist = 1;
	inter->color = s.color;
	inter->point = set_pointline(l, inter->dist + mu);
	if (inter->dist - (s.diam / 2) < -0.001)
		inter->normal = crea_vector(inter->point, s.coord);
	else
		inter->normal = crea_vector(s.coord, inter->point);
	ft_vec_normalization(&inter->normal);
	inter->object = SPHERE;
	return (1);
}

t_inter	inter_plan(t_line l, t_pl p)
{
	t_inter	inter;

	inter.exist = 0;
	if (ft_dot_product(l.dir, p.vec) == 0)
		return (inter);
	inter.dist = plan_dist(l, p);
	if (inter.dist < 0)
		return (inter);
	set_ex_p(&inter, l, p);
	return (inter);
}

t_inter	inter_sphere(t_line l, t_sp s)
{
	t_inter	inter;
	t_vec	normal;
	float	distance;
	float	mu;

	inter.exist = 0;
	normal = find_normal_line(l, s.coord, &inter.dist);
	distance = ft_square_length(normal);
	if (distance - (s.diam * s.diam) / 4 > 0.001)
		return (inter);
	distance = sqrt(distance);
	mu = (s.diam / 2) * sin(acos(distance / (s.diam / 2)));
	if (inter.dist - mu > 0 && set_ex_s(&inter, l, s, -mu))
		inter.dist -= mu;
	else if (inter.dist + mu > 0 && set_ex_s(&inter, l, s, mu))
		inter.dist += mu;
	return (inter);
}
