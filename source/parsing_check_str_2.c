/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_str_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:17:18 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/29 15:19:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_check_coordinate(t_var *m, char *s)
{
	char	**split;
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (s[++i])
		if (s[i] == ',')
			c++;
	if (c != 2)
		ft_error(m, 2);
	split = ft_split(s, ',');
	i = -1;
	while (split[++i])
		ft_check_correct_float_format(m, split[i]);
	if (i != 3)
		ft_error(m, 2);
	ft_free_split(split);
}

void	ft_check_normalization(t_var *m, char *s)
{
	char	**split;
	int		i;
	int		c;
	float	n;

	c = 0;
	i = -1;
	while (s[++i])
		if (s[i] == ',')
			c++;
	if (c != 2)
		ft_error(m, 2);
	split = ft_split(s, ',');
	i = -1;
	while (split[++i])
		ft_check_correct_float_format(m, split[i]);
	if (i != 3)
		ft_error(m, 2);
	n = ft_atof(split[0]) * ft_atof(split[0]) + ft_atof(split[1])
		* ft_atof(split[1]) + ft_atof(split[2]) * ft_atof(split[2]);
	if ((1.0 - n < -0.0000001) | (1.0 - n > 0.0000001))
		ft_error(m, 2);
	ft_free_split(split);
}

void	ft_check_fov(t_var *m, char *s)
{
	float	fov;

	ft_check_correct_float_format(m, s);
	fov = ft_atof(s);
	if (fov - 180.0 > 0.000001 || fov - 0.0 < 0)
		ft_error(m, 2);
}

void	ft_check_dimension(t_var *m, char *s)
{
	float	size;

	ft_check_correct_float_format(m, s);
	size = ft_atof(s);
	if (size - 0.0 < 0)
		ft_error(m, 2);
}

void	ft_check_only_digit_and_comma(t_var *m, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(ft_isdigit(s[i]) || s[i] == ','))
			ft_error(m, 2);
}
