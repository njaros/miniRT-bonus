/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:59:28 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 13:22:16 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_clean(char **tab)
{
	int	j;

	j = -1;
	while (tab[++j])
		free(tab[j]);
	free(tab);
	return ;
}

static int	ft_size(const char *s, char c)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			counter++;
		else if (counter > 0)
		{
			j++;
			counter = 0;
		}
		i++;
	}
	if (counter > 0)
		j++;
	return (j);
}

static void	ft_write(const char *s, char **strsplit, char c)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			strsplit[j][counter] = s[i];
			counter++;
		}
		else if (counter > 0)
		{
			strsplit[j][counter] = '\0';
			j++;
			counter = 0;
		}
		i++;
	}
	if (counter > 0)
		strsplit[j][counter] = '\0';
}

static void	ft_subsize(const char *s, char **strsplit, char c)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			counter++;
		else if (counter > 0)
		{
			strsplit[j] = ft_calloc(counter + 1, 1);
			if (!strsplit[j] && j < ft_size(s, c))
				ft_clean (strsplit);
			j++;
			counter = 0;
		}
		i++;
	}
	if (counter > 0)
		strsplit[j] = ft_calloc(counter + 1, 1);
	if (!strsplit[j] && j < ft_size(s, c))
		ft_clean (strsplit);
}

char	**ft_split(char const *s, char c)
{
	char	**strsplit;

	if (!s)
		return (NULL);
	strsplit = ft_calloc((ft_size(s, c) + 1), sizeof(char *));
	if (!strsplit)
		return (NULL);
	strsplit[ft_size(s, c)] = NULL;
	ft_subsize(s, strsplit, c);
	ft_write(s, strsplit, c);
	return (strsplit);
}
