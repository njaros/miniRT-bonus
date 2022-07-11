/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:32:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 13:20:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_exit(t_var *m, int i)
{
	free (m->ele.struc_l);
	free (m->ele.struc_sp);
	free (m->ele.struc_pl);
	free (m->ele.struc_cy);
	exit (i);
}

void	ft_error(t_var *m, int nb)
{
	if (nb == 1)
		printf("Error\nincorrect argument\n");
	if (nb == 2)
		printf("Error\nincorrect map\n");
	if (nb == 3)
		printf("Error\nfloat format error\n");
	if (nb == 4)
		printf("Error\ntoo many unique object\n");
	if (nb == 5)
		printf("Error\nmalloc error\n");
	if (nb == 6)
		printf("Error\nno camera\n");
	ft_exit (m, 0);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	if (split)
	{
		while (split[++i])
			free(split[i]);
		free(split);
	}
}

void	ft_super_free_split(char **s1, char **s2, char **s3, char **s4)
{
	ft_free_split(s1);
	ft_free_split(s2);
	ft_free_split(s3);
	ft_free_split(s4);
}
