/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:40:29 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/01 17:44:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	find_normal_line(t_line l, t_coord a, float *dist)
{
	t_coord	pos_normal;
	t_vec	normal;

	*dist = ft_dot_product(crea_vector(l.point, a), l.dir)
		/ ft_dot_product(l.dir, l.dir);
	pos_normal.x = l.point.x + *dist * l.dir.x;
	pos_normal.y = l.point.y + *dist * l.dir.y;
	pos_normal.z = l.point.z + *dist * l.dir.z;
	normal.x = pos_normal.x - a.x;
	normal.y = pos_normal.y - a.y;
	normal.z = pos_normal.z - a.z;
	return (normal);
}

t_coord	set_pointline(t_line l, float coef)
{
	t_coord	point;

	point.x = l.point.x + coef * l.dir.x;
	point.y = l.point.y + coef * l.dir.y;
	point.z = l.point.z + coef * l.dir.z;
	return (point);
}

float	plan_dist(t_line l, t_pl p)
{
	return (ft_dot_product(crea_vector(l.point, p.coord), p.vec) \
				/ ft_dot_product(l.dir, p.vec));
}

void	modif_pointline(t_line l, t_coord *point, float mu)
{
	point->x += mu * l.dir.x;
	point->y += mu * l.dir.y;
	point->z += mu * l.dir.z;
}

float	lines_normal_segment(t_line l1, t_line l2, t_inter *inter)
{
	t_pl	n_plan;
	float	dist_h1;
	t_coord	h1;
	t_vec	v1;

	v1 = vector_product(l1.dir, l2.dir);
	ft_vec_normalization(&v1);
	n_plan.vec = vector_product(l1.dir, v1);
	n_plan.coord = l1.point;
	inter->dist = plan_dist(l2, n_plan);
	inter->point = set_pointline(l2, inter->dist);
	dist_h1 = ft_dot_product(crea_vector(l1.point, inter->point), l1.dir) \
				/ ft_dot_product(l1.dir, l1.dir);
	h1 = set_pointline(l1, dist_h1);
	return (ft_square_length(crea_vector(h1, inter->point)));
}
