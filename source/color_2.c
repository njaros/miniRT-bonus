/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:38:52 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:45:17 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ft_reflexion(t_var *m, t_inter inter, t_line old_rt)
{
	t_color		color;
	t_line		line;
	static int	i = 0;

	ft_memset(&color, 0, sizeof(t_color));
	if (i < m->ref_num)
		i++;
	else
	{
		i = 0;
		return (color);
	}
	line = new_rt(old_rt, inter);
	color = ft_color_pixel(m, line);
	color.r *= m->ref_coef;
	color.g *= m->ref_coef;
	color.b *= m->ref_coef;
	return (color);
}

void	ft_add_color_2(t_color *color, t_color shad)
{
	color->r += shad.r;
	color->g += shad.g;
	color->b += shad.b;
}
