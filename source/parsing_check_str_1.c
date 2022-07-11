/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_str_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:09:59 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/30 10:42:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_check_extension(t_var *m, char *path)
{
	int	l;

	l = ft_strlen(path);
	if (l > 2)
	{
		if (path[l - 1] != 't' || path[l - 2] != 'r' || path[l - 3] != '.')
			ft_error(m, 2);
	}
	else
		ft_error(m, 2);
}

void	ft_check_imput(t_var *m, char *line)
{
	char	**split;
	int		i;

	i = -1;
	if (!line)
		ft_error (m, 2);
	split = ft_split(line, '\n');
	while (split[++i])
	{
		if (split[i][0] == 'A' && split[i][1] == ' ')
			ft_check_ambiante_lightning(m, split[i]);
		else if (split[i][0] == 'C' && split[i][1] == ' ')
			ft_check_camera(m, split[i]);
		else if (split[i][0] == 'L' && split[i][1] == ' ')
			ft_check_light(m, split[i]);
		else if (split[i][0] == 's' && split[i][1] == 'p' && split[i][2] == ' ')
			ft_check_sphere(m, split[i]);
		else if (split[i][0] == 'p' && split[i][1] == 'l' && split[i][2] == ' ')
			ft_check_plane(m, split[i]);
		else if (split[i][0] == 'c' && split[i][1] == 'y' && split[i][2] == ' ')
			ft_check_cylinder(m, split[i]);
		else
			ft_error(m, 2);
	}
	ft_free_split(split);
}

void	ft_check_correct_float_format(t_var *m, char *s)
{
	int			i;
	int			cs;
	const int	tbl[3][5] = {{2, -1, -1, -1, -1}, {3, 4, 3, 3, 4},
	{1, -1, 1, 4, -1}};

	cs = 0;
	i = -1;
	while (s[++i] && cs > -1)
	{
		if (s[i] == '-')
			cs = tbl[0][cs];
		else if (s[i] >= '0' && s[i] <= '9')
			cs = tbl[1][cs];
		else if (s[i] == '.')
			cs = tbl[2][cs];
		else
			cs = -1;
	}
	if (cs < 3)
		ft_error(m, 3);
}

void	ft_check_lightratio(t_var *m, char *s)
{
	float	r;

	ft_check_correct_float_format(m, s);
	r = ft_atof(s);
	if (r - 0.0 < 0 || r - 1 > 0.000001)
		ft_error(m, 2);
}

void	ft_check_color(t_var *m, char *s)
{
	int		i;
	int		c;
	char	**split;

	i = -1;
	c = 0;
	ft_check_only_digit_and_comma(m, s);
	while (s[++i])
		if (s[i] == ',')
			c++;
	if (c != 2)
		ft_error(m, 2);
	split = ft_split(s, ',');
	i = -1;
	while (split[++i])
	{
		if (split[i][0] == '0' && split[i][1] != '\0')
			ft_error(m, 2);
		if (ft_atoi(split[i]) > 255)
			ft_error(m, 2);
	}
	if (i != 3)
		ft_error(m, 2);
	ft_free_split(split);
}
