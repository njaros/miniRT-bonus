/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setUsefullMatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:19:23 by njaros            #+#    #+#             */
/*   Updated: 2022/06/29 15:19:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat	ft_mat_rotx(float rad)
{
	t_mat	rot_x;

	rot_x.a_a = 1;
	rot_x.a_b = 0;
	rot_x.a_c = 0;
	rot_x.b_a = 0;
	rot_x.b_b = cos(rad);
	rot_x.b_c = -sin(rad);
	rot_x.c_a = 0;
	rot_x.c_b = sin(rad);
	rot_x.c_c = cos(rad);
	return (rot_x);
}

t_mat	ft_mat_roty(float rad)
{
	t_mat	rot_y;

	rot_y.a_a = cos(rad);
	rot_y.a_b = 0;
	rot_y.a_c = sin(rad);
	rot_y.b_a = 0;
	rot_y.b_b = 1;
	rot_y.b_c = 0;
	rot_y.c_a = -sin(rad);
	rot_y.c_b = 0;
	rot_y.c_c = cos(rad);
	return (rot_y);
}

t_mat	ft_mat_rotz(float rad)
{
	t_mat	rot_z;

	rot_z.a_a = cos(rad);
	rot_z.a_b = -sin(rad);
	rot_z.a_c = 0;
	rot_z.b_a = sin(rad);
	rot_z.b_b = cos(rad);
	rot_z.b_c = 0;
	rot_z.c_a = 0;
	rot_z.c_b = 0;
	rot_z.c_c = 1;
	return (rot_z);
}
