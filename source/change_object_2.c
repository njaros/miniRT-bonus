/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_object_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:27:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/27 10:29:07 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_change_plane_2(t_var *m, int i)
{
	t_vec	tmp;

	ft_memset(&tmp, 0, sizeof(t_vec));
	tmp.x = 1;
	ft_mat_mat(ft_mat_rotz(m->ele.struc_pl[i].angle_x),
		ft_mat_roty(m->ele.struc_pl[i].angle_z), &m->ele.struc_pl[i].mat_rot);
	ft_mat_vec(tmp, m->ele.struc_pl[i].mat_rot, &m->ele.struc_pl[i].vec);
}
