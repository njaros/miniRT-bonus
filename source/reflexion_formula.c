/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion_formula.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:18:18 by njaros            #+#    #+#             */
/*   Updated: 2022/06/30 11:07:46 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_coord	add_vec(t_coord pt, t_vec v)
{
	t_coord	new;

	new.x = pt.x + v.x;
	new.y = pt.y + v.y;
	new.z = pt.z + v.z;
	return (new);
}

t_line	new_rt(t_line old_rt, t_inter i)
{
	t_line	new;
	t_line	tmp;
	float	dist;
	t_coord	tool;
	t_vec	v;

	dist = ft_dot_product(crea_vector(i.point, old_rt.point), i.normal);
	tmp.dir = i.normal;
	tmp.point = i.point;
	tool = set_pointline(tmp, dist);
	v = crea_vector(old_rt.point, tool);
	tool = add_vec(add_vec(old_rt.point, v), v);
	new.point = i.point;
	new.dir = crea_vector(new.point, tool);
	ft_vec_normalization(&new.dir);
	modif_pointline(new, &new.point, 0.0001);
	return (new);
}
