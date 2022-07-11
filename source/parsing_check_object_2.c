/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_object_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:12:20 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/27 16:36:05 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_check_cylinder(t_var *m, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 6)
		ft_error(m, 2);
	ft_check_coordinate(m, split[1]);
	ft_check_normalization(m, split[2]);
	ft_check_dimension(m, split[3]);
	ft_check_dimension(m, split[4]);
	ft_check_color(m, split[5]);
	m->ele.cy++;
	ft_free_split(split);
}
