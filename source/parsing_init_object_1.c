/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_object_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:52:41 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/01 14:49:15 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_init_ambiante_lightning(t_var *m, char *s)
{
	char	**split;
	char	**petit_split;

	split = ft_split(s, ' ');
	m->ele.struc_a.light_r = ft_atof(split[1]);
	petit_split = ft_split(split[2], ',');
	m->ele.struc_a.color.r = ft_atoi(petit_split[0]) / 255.0;
	m->ele.struc_a.color.g = ft_atoi(petit_split[1]) / 255.0;
	m->ele.struc_a.color.b = ft_atoi(petit_split[2]) / 255.0;
	ft_free_split(split);
	ft_free_split(petit_split);
}

static void	ft_init_camera(t_var *m, char *s)
{
	char	**split;
	char	**split_coord;
	char	**split_normal;

	split = ft_split(s, ' ');
	split_coord = ft_split(split[1], ',');
	split_normal = ft_split(split[2], ',');
	m->ele.struc_c.coord.x = ft_atof(split_coord[0]);
	m->ele.struc_c.coord.y = ft_atof(split_coord[1]);
	m->ele.struc_c.coord.z = ft_atof(split_coord[2]);
	m->ele.struc_c.vec.x = 1;
	m->ele.struc_c.vec.y = 0;
	m->ele.struc_c.vec.z = 0;
	m->ele.struc_c.fov = ft_atof(split[3]);
	m->ele.struc_c.angle_z = -asin(ft_atof(split_normal[2]) + 0.0001);
	m->ele.struc_c.angle_x = atan2(ft_atof(split_normal[1]) + 0.0001, ft_atof(split_normal[0]) + 0.0001);
	ft_mat_mat(ft_mat_rotz(m->ele.struc_c.angle_x),
		ft_mat_roty(m->ele.struc_c.angle_z), &m->mat_rot);
	ft_free_split(split);
	ft_free_split(split_coord);
	ft_free_split(split_normal);
}

static void	ft_init_light(t_var *m, char *s)
{
	char		**split;
	char		**split_coord;
	char		**split_color;
	static int	i = 0;

	split = ft_split(s, ' ');
	split_coord = ft_split(split[1], ',');
	split_color = ft_split(split[3], ',');
	m->ele.struc_l[i].coord.x = ft_atof(split_coord[0]);
	m->ele.struc_l[i].coord.y = ft_atof(split_coord[1]);
	m->ele.struc_l[i].coord.z = ft_atof(split_coord[2]);
	m->ele.struc_l[i].color.r = ft_atoi(split_color[0]) / 255.0;
	m->ele.struc_l[i].color.g = ft_atoi(split_color[1]) / 255.0;
	m->ele.struc_l[i].color.b = ft_atoi(split_color[2]) / 255.0;
	m->ele.struc_l[i].light_r = ft_atof(split[2]);
	i++;
	ft_free_split(split);
	ft_free_split(split_coord);
	ft_free_split(split_color);
}

static void	ft_init_sphere(t_var *m, char *s)
{
	static int	i = 0;
	char		**split;
	char		**split_color;
	char		**split_coord;

	split = ft_split(s, ' ');
	split_color = ft_split(split[3], ',');
	split_coord = ft_split(split[1], ',');
	m->ele.struc_sp[i].color.r = ft_atoi(split_color[0]) / 255.0;
	m->ele.struc_sp[i].color.g = ft_atoi(split_color[1]) / 255.0;
	m->ele.struc_sp[i].color.b = ft_atoi(split_color[2]) / 255.0;
	m->ele.struc_sp[i].coord.x = ft_atof(split_coord[0]);
	m->ele.struc_sp[i].coord.y = ft_atof(split_coord[1]);
	m->ele.struc_sp[i].coord.z = ft_atof(split_coord[2]);
	m->ele.struc_sp[i].diam = ft_atof(split[2]);
	i++;
	ft_free_split(split);
	ft_free_split(split_color);
	ft_free_split(split_coord);
}

void	ft_imput_init(t_var *m, char *s)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(s, '\n');
	while (split[++i])
	{
		if (split[i][0] == 'A' && split[i][1] == ' ')
			ft_init_ambiante_lightning(m, split[i]);
		else if (split[i][0] == 'C' && split[i][1] == ' ')
			ft_init_camera(m, split[i]);
		else if (split[i][0] == 'L' && split[i][1] == ' ')
			ft_init_light(m, split[i]);
		else if (split[i][0] == 's' && split[i][1] == 'p' && split[i][2] == ' ')
			ft_init_sphere(m, split[i]);
		else if (split[i][0] == 'p' && split[i][1] == 'l' && split[i][2] == ' ')
			ft_init_plane(m, split[i]);
		else
			ft_init_cylinder(m, split[i]);
	}
	ft_free_split(split);
}
