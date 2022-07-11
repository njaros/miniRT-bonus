/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:20:05 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/02 14:20:07 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < size - 1)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strchr(char *string, int c)
{
	while (*string)
	{
		if (*string == (char)c)
			return (string);
		string++;
	}
	if (*string == '\0' && c == '\0')
		return (string);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
