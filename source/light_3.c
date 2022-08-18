/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:58:04 by jrinna            #+#    #+#             */
/*   Updated: 2022/08/16 10:16:27 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	in_sphere_mem(float dist)
{
	return (dist < 0);
}

int	ft_check_check(t_var *m, t_line l_line, float lg_segment)
{
	if (check_light_inter_plan(m, l_line, lg_segment))
		return (1);
	if (check_light_inter_sph(m, l_line, lg_segment))
		return (1);
	if (check_light_inter_cyl(m, l_line, lg_segment))
		return (1);
	return (0);
}
