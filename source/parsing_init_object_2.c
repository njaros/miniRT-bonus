/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_object_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:30:01 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:42:10 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_init_plan_2(t_var *m, int i)
{
	ft_mat_mat(ft_mat_rotz(m->ele.struc_pl[i].angle_x),
		ft_mat_roty(m->ele.struc_pl[i].angle_z), &m->ele.struc_pl[i].mat_rot);
}

void	ft_init_plane(t_var *m, char *s)
{
	static int	i = 0;
	char		**split;
	char		**split_normal;
	char		**split_color;
	char		**split_coord;

	split = ft_split(s, ' ');
	split_color = ft_split(split[3], ',');
	split_coord = ft_split(split[1], ',');
	split_normal = ft_split(split[2], ',');
	m->ele.struc_pl[i].color.r = ft_atoi(split_color[0]) / 255.0;
	m->ele.struc_pl[i].color.g = ft_atoi(split_color[1]) / 255.0;
	m->ele.struc_pl[i].color.b = ft_atoi(split_color[2]) / 255.0;
	m->ele.struc_pl[i].coord.x = ft_atof(split_coord[0]);
	m->ele.struc_pl[i].coord.y = ft_atof(split_coord[1]);
	m->ele.struc_pl[i].coord.z = ft_atof(split_coord[2]);
	m->ele.struc_pl[i].vec.x = ft_atof(split_normal[0]);
	m->ele.struc_pl[i].vec.y = ft_atof(split_normal[1]);
	m->ele.struc_pl[i].vec.z = ft_atof(split_normal[2]);
	m->ele.struc_pl[i].angle_z = -asin(m->ele.struc_pl[i].vec.z);
	m->ele.struc_pl[i].angle_x = atan2(m->ele.struc_pl[i].vec.y,
			m->ele.struc_pl[i].vec.x);
	ft_init_plan_2(m, i);
	i++;
	ft_super_free_split(split, split_color, split_coord, split_normal);
}

t_pl	set_plan_up(t_cy cy)
{
	t_pl	plan_up;
	t_line	tool;

	tool.dir = cy.vec;
	tool.point = cy.coord;
	plan_up.vec = cy.vec;
	plan_up.coord = set_pointline(tool, cy.height);
	return (plan_up);
}

void	ft_init_cylinder_suite(t_var *m, int i)
{
	m->ele.struc_cy[i].angle_z = -asin(m->ele.struc_cy[i].vec.z);
	m->ele.struc_cy[i].angle_x = atan2(m->ele.struc_cy[i].vec.y,
			m->ele.struc_cy[i].vec.x);
	ft_mat_mat(ft_mat_rotz(m->ele.struc_cy[i].angle_x),
		ft_mat_roty(m->ele.struc_cy[i].angle_z), &m->ele.struc_cy[i].mat_rot);
	m->ele.struc_cy[i].plan_down = set_plan_down(m->ele.struc_cy[i]);
	m->ele.struc_cy[i].plan_up = set_plan_up(m->ele.struc_cy[i]);
}

void	ft_init_cylinder(t_var *m, char *s)
{
	static int	i = 0;
	char		**split;
	char		**split_normal;
	char		**split_color;
	char		**split_coord;

	split = ft_split(s, ' ');
	split_color = ft_split(split[5], ',');
	split_coord = ft_split(split[1], ',');
	split_normal = ft_split(split[2], ',');
	m->ele.struc_cy[i].color.r = ft_atoi(split_color[0]) / 255.0;
	m->ele.struc_cy[i].color.g = ft_atoi(split_color[1]) / 255.0;
	m->ele.struc_cy[i].color.b = ft_atoi(split_color[2]) / 255.0;
	m->ele.struc_cy[i].coord.x = ft_atof(split_coord[0]);
	m->ele.struc_cy[i].coord.y = ft_atof(split_coord[1]);
	m->ele.struc_cy[i].coord.z = ft_atof(split_coord[2]);
	m->ele.struc_cy[i].vec.x = ft_atof(split_normal[0]);
	m->ele.struc_cy[i].vec.y = ft_atof(split_normal[1]);
	m->ele.struc_cy[i].vec.z = ft_atof(split_normal[2]);
	m->ele.struc_cy[i].diam = ft_atof(split[3]);
	m->ele.struc_cy[i].height = ft_atof(split[4]);
	ft_init_cylinder_suite(m, i);
	i++;
	ft_super_free_split(split, split_color, split_coord, split_normal);
}
