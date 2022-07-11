/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:00:39 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 13:22:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_parsing(t_var *m, char *path)
{
	int		fd;
	char	*line;

	ft_check_extension(m, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(m, 2);
	line = ft_get_file(fd);
	ft_check_imput(m, line);
	m->ele.struc_sp = ft_calloc(m->ele.sp, sizeof(t_sp));
	m->ele.struc_pl = ft_calloc(m->ele.pl, sizeof(t_pl));
	m->ele.struc_cy = ft_calloc(m->ele.cy, sizeof(t_cy));
	m->ele.struc_l = ft_calloc(m->ele.l, sizeof(t_l));
	ft_imput_init(m, line);
	free (line);
}

t_pl	set_plan_down(t_cy cy)
{
	t_pl	plan_down;

	plan_down.vec.x = -cy.vec.x;
	plan_down.vec.y = -cy.vec.y;
	plan_down.vec.z = -cy.vec.z;
	plan_down.coord = cy.coord;
	return (plan_down);
}
