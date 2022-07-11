/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:58:04 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/29 15:19:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
