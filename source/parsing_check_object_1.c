/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_object_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:47:40 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/27 16:35:46 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_check_ambiante_lightning(t_var *m, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	if (m->ele.a)
		ft_error(m, 4);
	while (split[i])
		i++;
	if (i != 3)
		ft_error(m, 2);
	ft_check_lightratio(m, split[1]);
	ft_check_color(m, split[2]);
	m->ele.a++;
	ft_free_split(split);
}

void	ft_check_camera(t_var *m, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	if (m->ele.c)
		ft_error(m, 4);
	while (split[i])
		i++;
	if (i != 4)
		ft_error(m, 2);
	ft_check_coordinate(m, split[1]);
	ft_check_normalization(m, split[2]);
	ft_check_fov(m, split[3]);
	m->ele.c++;
	ft_free_split(split);
}

void	ft_check_light(t_var *m, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
		ft_error(m, 2);
	ft_check_coordinate(m, split[1]);
	ft_check_lightratio(m, split[2]);
	ft_check_color(m, split[3]);
	m->ele.l++;
	ft_free_split(split);
}

void	ft_check_sphere(t_var *m, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
		ft_error(m, 2);
	ft_check_coordinate(m, split[1]);
	ft_check_dimension(m, split[2]);
	ft_check_color(m, split[3]);
	m->ele.sp++;
	ft_free_split(split);
}

void	ft_check_plane(t_var *m, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
		ft_error(m, 2);
	ft_check_coordinate(m, split[1]);
	ft_check_normalization(m, split[2]);
	ft_check_color(m, split[3]);
	m->ele.pl++;
	ft_free_split(split);
}
