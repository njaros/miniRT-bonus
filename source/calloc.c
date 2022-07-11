/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:13:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 13:22:39 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_memset(void *block, int c, unsigned long size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		*(unsigned char *)(block + i) = (unsigned char)c;
		i++;
	}
}

void	*ft_calloc(int count, int eltsize)
{
	int		i;
	char	*block;

	i = -1;
	block = malloc(count * eltsize);
	if (block)
		while (++i < count * eltsize)
			*(block + i) = 0;
	return ((void *)block);
}
