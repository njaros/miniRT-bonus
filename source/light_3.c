/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:58:04 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 14:54:19 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	in_sphere_mem(float dist)
{
	if (dist < 0)
		return(1);
	return (0);
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
