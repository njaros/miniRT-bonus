/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:30:28 by njaros            #+#    #+#             */
/*   Updated: 2022/07/01 13:55:14 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	paralel_dist(t_line l1, t_line l2)
{
	t_pl	n_plan;
	t_coord	n_pt;

	n_plan.coord = l1.point;
	n_plan.vec = l1.dir;
	n_pt = set_pointline(l2, plan_dist(l2, n_plan));
	return (ft_vec_lenght(crea_vector(n_pt, l1.point)));
}
