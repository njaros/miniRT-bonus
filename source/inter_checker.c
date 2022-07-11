/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:40:10 by njaros            #+#    #+#             */
/*   Updated: 2022/06/24 10:26:38 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	check_inter_plan(int nb, t_pl *p, t_line l, t_inter inter)
{
	t_inter	temp;

	while (nb)
	{
		temp = inter_plan(l, p[--nb]);
		if (temp.exist)
		{
			if (!inter.exist)
				inter = temp;
			else if (temp.dist < inter.dist)
				inter = temp;
		}
	}
	return (inter);
}

t_inter	check_inter_sphere(int nb, t_sp *s, t_line l, t_inter inter)
{
	t_inter	temp;

	while (nb)
	{
		temp = inter_sphere(l, s[--nb]);
		if (temp.exist)
		{
			if (!inter.exist)
				inter = temp;
			else if (temp.dist < inter.dist)
				inter = temp;
		}
	}
	return (inter);
}

t_inter	check_inter_cylinder(int nb, t_cy *c, t_line l, t_inter inter)
{
	t_inter	temp;

	while (nb)
	{
		temp = inter_cylinder(l, c[--nb]);
		if (temp.exist)
		{
			if (!inter.exist)
				inter = temp;
			else if (temp.dist < inter.dist)
				inter = temp;
		}
	}
	return (inter);
}

t_inter	inter_checker(t_line l, t_ele e)
{
	t_inter	inter;

	inter.exist = 0;
	inter = check_inter_plan(e.pl, e.struc_pl, l, inter);
	inter = check_inter_sphere(e.sp, e.struc_sp, l, inter);
	inter = check_inter_cylinder(e.cy, e.struc_cy, l, inter);
	return (inter);
}
