/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:06:59 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:43:18 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_imput_cylinder(int key, t_var *m)
{
	static int	i = 0;

	if (key == K_SPHERE)
		return (1);
	if (key == K_CAMERA)
		return (0);
	if (key == K_PLANE)
		return (3);
	if (key == K_LIGHT)
		return (4);
	if (key == K_PLUS)
		i++;
	if (key == K_MINUS)
		i--;
	if (i > m->ele.cy - 1)
		i = 0;
	if (i < 0)
		i = m->ele.cy - 1;
	if (i < m->ele.cy)
		ft_change_cylinder(key, m, i);
	return (2);
}

static int	ft_imput_plane(int key, t_var *m)
{
	static int	i = 0;

	if (key == K_SPHERE)
		return (1);
	if (key == K_CYLINDER)
		return (2);
	if (key == K_CAMERA)
		return (0);
	if (key == K_LIGHT)
		return (4);
	if (key == K_PLUS)
		i++;
	if (key == K_MINUS)
		i--;
	if (i > m->ele.pl - 1)
		i = 0;
	if (i < 0)
		i = m->ele.pl - 1;
	if (i < m->ele.pl)
		ft_change_plane(key, m, i);
	return (3);
}

static int	ft_imput_light(int key, t_var *m)
{
	static int	i = 0;

	if (key == K_SPHERE)
		return (1);
	if (key == K_CYLINDER)
		return (2);
	if (key == K_PLANE)
		return (3);
	if (key == K_CAMERA)
		return (0);
	if (key == K_PLUS)
		i++;
	if (key == K_MINUS)
		i--;
	if (i > m->ele.l - 1)
		i = 0;
	if (i < 0)
		i = m->ele.l - 1;
	if (i < m->ele.l)
		ft_change_light(key, m, i);
	return (4);
}

static int	ft_imput_camera(int key, t_var *m)
{
	if (key == K_SPHERE)
		return (1);
	if (key == K_CYLINDER)
		return (2);
	if (key == K_PLANE)
		return (3);
	if (key == K_LIGHT)
		return (4);
	if (key == K_REFLEXION)
		return (5);
	if (key == K_RIGHT)
		m->ele.struc_c.angle_x += -5 * (2 * PI / 360);
	if (key == K_LEFT)
		m->ele.struc_c.angle_x += 5 * (2 * PI / 360);
	if (key == K_UP)
		m->ele.struc_c.angle_z += -5 * (2 * PI / 360);
	if (key == K_DOWN)
		m->ele.struc_c.angle_z += 5 * (2 * PI / 360);
	if (key == K_FRONT)
		ft_move_cam(m, 1);
	if (key == K_BACK)
		ft_move_cam(m, -1);
	return (0);
}

int	ft_imput_first(int key, void *mm)
{
	t_var		*m;
	static int	i = 0;

	m = (t_var *)mm;
	mlx_clear_window(m->init, m->win.ptr);
	if (key == K_ESC)
		ft_exit (m, 0);
	else if (i == 0)
		i = ft_imput_camera(key, m);
	else if (i == 1)
		i = ft_imput_sphere(key, m);
	else if (i == 2)
		i = ft_imput_cylinder(key, m);
	else if (i == 3)
		i = ft_imput_plane(key, m);
	else if (i == 4)
		i = ft_imput_light(key, m);
	else if (i == 5)
		i = ft_imput_reflexion(key, m);
	ft_image_render(m);
	return (0);
}
