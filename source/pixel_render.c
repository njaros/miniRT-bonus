/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:18:17 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/11 09:57:23 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	color_inter(t_var *m, t_inter inter, t_line line)
{
	int		i;
	float	ratio;
	t_color	color_amb;
	t_color	color_shad;
	t_color	color_refl;

	i = -1;
	ratio = 0;
	ft_memset(&color_shad, 0, sizeof(t_color));
	ft_memset(&color_refl, 0, sizeof(t_color));
	ft_memset(&color_amb, 0, sizeof(t_color));
	color_amb = ft_ambiant_light(m, inter.color);
	while (++i < m->ele.l)
		if (ft_inter_light(m, m->ele.struc_l[i], inter, &ratio))
			ft_add_color_2(&color_shad, ft_shadow_light(m, i, ratio,
					inter.color));
	color_refl = ft_reflexion(m, inter, line);
	return (ft_add_color(m, color_amb, color_shad, color_refl));
}

t_color	ft_color_pixel(t_var *m, t_line line)
{
	t_inter	inter;
	t_color	pixel_color;

	inter = inter_checker(line, m->ele);
	if (inter.exist)
		pixel_color = color_inter(m, inter, line);
	else
		pixel_color = ft_skybox_color(m, line.dir);
	return (pixel_color);
}

void	ft_pixel_put(t_var *m, int i, int j, t_vec v)
{
	t_line	line;
	int		pixel_color;
	t_color	color;
	char	*dst;

	pixel_color = 0;
	line.dir = v;
	line.point = m->ele.struc_c.coord;
	color = ft_color_pixel(m, line);
	pixel_color += ft_min((int)(color.r * 255), 255) << 16;
	pixel_color += ft_min((int)(color.g * 255), 255) << 8;
	pixel_color += ft_min((int)(color.b * 255), 255);
	pixel_color += 0 << 24;
	dst = m->img.adr + (i * m->img.line_lengh + j * (m->img.bpp / 8));
	*(unsigned int *)dst = pixel_color;
}

void	ft_image_render(t_var *m)
{
	if (!m->ele.c)
		ft_error(m, 6);
	m->img.ptr = mlx_new_image(m->init, m->win.lenght, m->win.height);
	m->img.adr = mlx_get_data_addr(m->img.ptr, &m->img.bpp, &m->img.line_lengh,
			&m->img.endian);
	ft_mat_mat(ft_mat_rotz(m->ele.struc_c.angle_x),
		ft_mat_roty(m->ele.struc_c.angle_z), &m->mat_rot);
	thread_manager(m);
	mlx_put_image_to_window(m->init, m->win.ptr, m->img.ptr, 0, 0);
}