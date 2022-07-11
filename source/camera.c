/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:40:08 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 15:34:08 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_move_cam(t_var *m, int s)
{
	t_vec	camera;

	ft_mat_vec(m->ele.struc_c.vec, m->mat_rot, &camera);
	m->ele.struc_c.coord.x += camera.x * s;
	m->ele.struc_c.coord.y += camera.y * s;
	m->ele.struc_c.coord.z += camera.z * s;
}
