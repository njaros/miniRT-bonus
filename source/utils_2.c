/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:19:58 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 13:22:20 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	new_string = ft_calloc(ft_strlen_s(s1) + ft_strlen_s(s2) + 1, 1);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			new_string[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			new_string[j++] = s2[i++];
	free(s1);
	return (new_string);
}

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_min(int a, int b)
{
	if (b > a)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (b < a)
		return (a);
	else
		return (b);
}
