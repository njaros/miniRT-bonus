/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:06:17 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:43:24 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_please_stop(void *m)
{
	(void)m;
	exit(0);
}

int	ft_imput_sphere(int key, t_var *m)
{
	static int	i = 0;

	if (key == K_CAMERA)
		return (0);
	if (key == K_CYLINDER)
		return (2);
	if (key == K_PLANE)
		return (3);
	if (key == K_LIGHT)
		return (4);
	if (key == K_PLUS)
		i++;
	if (key == K_MINUS)
		i--;
	if (i > m->ele.sp - 1)
		i = 0;
	if (i < 0)
		i = m->ele.sp - 1;
	if (i < m->ele.sp)
		ft_change_sphere(key, m, i);
	return (1);
}

int	ft_imput_reflexion(int key, t_var *m)
{
	if (key == K_CAMERA)
		return (0);
	if (key == K_SPHERE)
		return (1);
	if (key == K_CYLINDER)
		return (2);
	if (key == K_PLANE)
		return (3);
	if (key == K_LIGHT)
		return (4);
	if (key == K_PLUS)
		m->ref_num += 1;
	if (key == K_MINUS)
		m->ref_num -= 1;
	if (key == K_UP)
		m->ref_coef += .05;
	if (key == K_DOWN)
		m->ref_coef -= .05;
	if (m->ref_coef < 0)
		m->ref_coef = 0;
	if (m->ref_coef > 1)
		m->ref_coef = 1;
	return (5);
}
