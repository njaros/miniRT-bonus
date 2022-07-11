/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:19:14 by njaros            #+#    #+#             */
/*   Updated: 2022/06/29 15:19:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ft_dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vector_product(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vec	crea_vector(t_coord a, t_coord b)
{
	t_vec	result;

	result.x = b.x - a.x;
	result.y = b.y - a.y;
	result.z = b.z - a.z;
	return (result);
}

float	coef_point(t_coord pt, t_line l)
{
	if (l.dir.x)
		return ((pt.x - l.point.x) / l.dir.x);
	if (l.dir.y)
		return ((pt.y - l.point.y) / l.dir.y);
	if (l.dir.z)
		return ((pt.z - l.point.z) / l.dir.z);
	else
		return (0);
}

float	distance_projection(t_line l, t_coord a)
{
	return (ft_dot_product(crea_vector(l.point, a), l.dir) \
			/ ft_dot_product(l.dir, l.dir));
}
