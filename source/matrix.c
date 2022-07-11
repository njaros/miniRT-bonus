/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:58:43 by njaros            #+#    #+#             */
/*   Updated: 2022/06/29 15:19:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_mat_vec(t_vec ov, t_mat mat, t_vec *nv)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = ov.x * mat.a_a + ov.y * mat.a_b + ov.z * mat.a_c;
	tmp_y = ov.x * mat.b_a + ov.y * mat.b_b + ov.z * mat.b_c;
	nv->z = ov.x * mat.c_a + ov.y * mat.c_b + ov.z * mat.c_c;
	nv->x = tmp_x;
	nv->y = tmp_y;
}

void	ft_mat_mat(t_mat m1, t_mat m2, t_mat *new)
{
	new->a_a = m1.a_a * m2.a_a + m1.a_b * m2.b_a + m1.a_c * m2.c_a;
	new->a_b = m1.a_a * m2.a_b + m1.a_b * m2.b_b + m1.a_c * m2.c_b;
	new->a_c = m1.a_a * m2.a_c + m1.a_b * m2.b_c + m1.a_c * m2.c_c;
	new->b_a = m1.b_a * m2.a_a + m1.b_b * m2.b_a + m1.b_c * m2.c_a;
	new->b_b = m1.b_a * m2.a_b + m1.b_b * m2.b_b + m1.b_c * m2.c_b;
	new->b_c = m1.b_a * m2.a_c + m1.b_b * m2.b_c + m1.b_c * m2.c_c;
	new->c_a = m1.c_a * m2.a_a + m1.c_b * m2.b_a + m1.c_c * m2.c_a;
	new->c_b = m1.c_a * m2.a_b + m1.c_b * m2.b_b + m1.c_c * m2.c_b;
	new->c_c = m1.c_a * m2.a_c + m1.c_b * m2.b_c + m1.c_c * m2.c_c;
}

void	ft_add_mat_mat(t_mat m1, t_mat m2, t_mat *new)
{
	new->a_a = m1.a_a + m2.a_a;
	new->a_b = m1.a_b + m2.a_b;
	new->a_c = m1.a_c + m2.a_c;
	new->b_a = m1.b_a + m2.b_a;
	new->b_b = m1.b_b + m2.b_b;
	new->b_c = m1.b_c + m2.b_c;
	new->c_a = m1.c_a + m2.c_a;
	new->c_b = m1.c_b + m2.c_b;
	new->c_c = m1.c_c + m2.c_c;
}

float	ft_determinant(t_mat mat)
{
	float	result;

	result = 0;
	result += mat.a_a * mat.b_b * mat.c_c;
	result += mat.a_b * mat.b_c * mat.c_a;
	result += mat.a_c * mat.b_b * mat.c_b;
	result -= mat.c_a * mat.b_b * mat.a_c;
	result -= mat.c_b * mat.b_c * mat.a_a;
	result -= mat.c_c * mat.b_a * mat.a_b;
	return (result);
}

t_mat	mat_compose(t_vec v1, t_vec v2, t_vec v3)
{
	t_mat	mat;

	mat.a_a = v1.x;
	mat.b_a = v1.y;
	mat.c_a = v1.z;
	mat.b_a = v2.x;
	mat.b_b = v2.y;
	mat.b_c = v2.z;
	mat.c_a = v3.x;
	mat.c_b = v3.y;
	mat.c_c = v3.z;
	return (mat);
}
