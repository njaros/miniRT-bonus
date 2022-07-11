/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_object_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:27:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:45:36 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_change_plane(int key, t_var *m, int i)
{
	if (key == K_RIGHT)
		m->ele.struc_pl[i].coord.y += -1;
	if (key == K_LEFT)
		m->ele.struc_pl[i].coord.y += 1;
	if (key == K_UP)
		m->ele.struc_pl[i].coord.z += 1;
	if (key == K_DOWN)
		m->ele.struc_pl[i].coord.z += -1;
	if (key == K_FRONT)
		m->ele.struc_pl[i].coord.x += 1;
	if (key == K_BACK)
		m->ele.struc_pl[i].coord.x += -1;
	if (key == K_L)
		m->ele.struc_pl[i].angle_x += -(2 * PI / 360);
	if (key == K_J)
		m->ele.struc_pl[i].angle_x += (2 * PI / 360);
	if (key == K_I)
		m->ele.struc_pl[i].angle_z += -(2 * PI / 360);
	if (key == K_K)
		m->ele.struc_pl[i].angle_z += (2 * PI / 360);
	ft_change_plane_2(m, i);
}

void	ft_change_sphere(int key, t_var *m, int i)
{
	if (key == K_RIGHT)
		m->ele.struc_sp[i].coord.y += -1;
	if (key == K_LEFT)
		m->ele.struc_sp[i].coord.y += 1;
	if (key == K_UP)
		m->ele.struc_sp[i].coord.z += 1;
	if (key == K_DOWN)
		m->ele.struc_sp[i].coord.z += -1;
	if (key == K_FRONT)
		m->ele.struc_sp[i].coord.x += 1;
	if (key == K_BACK)
		m->ele.struc_sp[i].coord.x += -1;
	if (key == K_E)
		m->ele.struc_sp[i].diam += 1;
	if (key == K_Q)
		m->ele.struc_sp[i].diam += -1;
}

void	ft_change_light(int key, t_var *m, int i)
{
	if (key == K_RIGHT)
		m->ele.struc_l[i].coord.y += -1;
	if (key == K_LEFT)
		m->ele.struc_l[i].coord.y += 1;
	if (key == K_UP)
		m->ele.struc_l[i].coord.z += 1;
	if (key == K_DOWN)
		m->ele.struc_l[i].coord.z += -1;
	if (key == K_FRONT)
		m->ele.struc_l[i].coord.x += 1;
	if (key == K_BACK)
		m->ele.struc_l[i].coord.x += -1;
}

void	ft_change_cylinder_2(int key, t_var *m, int i)
{
	t_vec	tmp;

	tmp.x = 1;
	tmp.y = 0;
	tmp.z = 0;
	if (key == K_L)
		m->ele.struc_cy[i].angle_x += -(2 * PI / 360);
	if (key == K_J)
		m->ele.struc_cy[i].angle_x += (2 * PI / 360);
	if (key == K_I)
		m->ele.struc_cy[i].angle_z += -(2 * PI / 360);
	if (key == K_K)
		m->ele.struc_cy[i].angle_z += (2 * PI / 360);
	ft_mat_mat(ft_mat_rotz(m->ele.struc_cy[i].angle_x),
		ft_mat_roty(m->ele.struc_cy[i].angle_z), &m->ele.struc_cy[i].mat_rot);
	ft_mat_vec(tmp, m->ele.struc_cy[i].mat_rot, &m->ele.struc_cy[i].vec);
	m->ele.struc_cy[i].plan_down = set_plan_down(m->ele.struc_cy[i]);
	m->ele.struc_cy[i].plan_up = set_plan_up(m->ele.struc_cy[i]);
}

void	ft_change_cylinder(int key, t_var *m, int i)
{
	if (key == K_RIGHT)
		m->ele.struc_cy[i].coord.y += -1;
	if (key == K_LEFT)
		m->ele.struc_cy[i].coord.y += 1;
	if (key == K_UP)
		m->ele.struc_cy[i].coord.z += 1;
	if (key == K_DOWN)
		m->ele.struc_cy[i].coord.z += -1;
	if (key == K_FRONT)
		m->ele.struc_cy[i].coord.x += 1;
	if (key == K_BACK)
		m->ele.struc_cy[i].coord.x += -1;
	if (key == K_E)
		m->ele.struc_cy[i].diam += 1;
	if (key == K_Q)
		m->ele.struc_cy[i].diam += -1;
	if (key == K_X)
		m->ele.struc_cy[i].height += 1;
	if (key == K_Z)
		m->ele.struc_cy[i].height += -1;
	ft_change_cylinder_2(key, m, i);
}
