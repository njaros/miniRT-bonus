/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:17:11 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/29 15:19:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ft_vec_lenght(t_vec x)
{
	return (sqrt(x.x * x.x + x.y * x.y + x.z * x.z));
}

float	ft_square_length(t_vec x)
{
	return (x.x * x.x + x.y * x.y + x.z * x.z);
}

void	ft_vec_normalization(t_vec *old)
{
	t_vec	new;
	float	lenght;

	lenght = ft_vec_lenght(*old);
	new.x = old->x / lenght;
	new.y = old->y / lenght;
	new.z = old->z / lenght;
	*old = new;
}
