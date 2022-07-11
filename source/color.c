/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:18:07 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:45:12 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ft_skybox_color(t_var *m, t_vec v)
{
	t_color	color;

	ft_memset(&color, 0, sizeof(t_color));
	if (fabs(v.x) >= fabs(v.y) && fabs(v.x) >= fabs(v.z))
		color.r = ((v.x + 1) / 2.0) * m->ele.struc_a.color.r
			* m->ele.struc_a.light_r;
	if (fabs(v.y) >= fabs(v.x) && fabs(v.y) >= fabs(v.z))
		color.g = ((v.y + 1) / 2.0) * m->ele.struc_a.color.g
			* m->ele.struc_a.light_r;
	if (fabs(v.z) >= fabs(v.x) && fabs(v.z) >= fabs(v.y))
		color.b = ((v.z + 1) / 2.0) * m->ele.struc_a.color.b
			* m->ele.struc_a.light_r;
	return (color);
}

void	ft_color_reset(t_var *m)
{
	ft_memset(&m->amb, 0, sizeof(t_color));
	ft_memset(&m->shad, 0, sizeof(t_color));
	ft_memset(&m->refl, 0, sizeof(t_color));
	ft_memset(&m->color, 0, sizeof(t_color));
}

t_color	ft_shadow_light(t_var *m, int i, float ratio, t_color objcol)
{
	t_color	color;

	color.r = m->ele.struc_l[i].color.r * objcol.r
		* m->ele.struc_l[i].light_r * ratio;
	color.g = m->ele.struc_l[i].color.g * objcol.g
		* m->ele.struc_l[i].light_r * ratio;
	color.b = m->ele.struc_l[i].color.b * objcol.b
		* m->ele.struc_l[i].light_r * ratio;
	return (color);
}

t_color	ft_ambiant_light(t_var *m, t_color object_color)
{
	t_color	color;

	color.r = object_color.r * m->ele.struc_a.color.r * m->ele.struc_a.light_r;
	color.g = object_color.g * m->ele.struc_a.color.g * m->ele.struc_a.light_r;
	color.b = object_color.b * m->ele.struc_a.color.b * m->ele.struc_a.light_r;
	return (color);
}

t_color	ft_add_color(t_var *m, t_color amb, t_color shad, t_color refl)
{
	t_color	color;

	color.r = amb.r + shad.r + refl.r * m->ref_coef;
	color.g = amb.g + shad.g + refl.g * m->ref_coef;
	color.b = amb.b + shad.b + refl.b * m->ref_coef;
	return (color);
}
