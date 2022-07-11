/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:02:17 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/07 12:45:29 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*ft_get_file(int fd)
{
	char	buff[1024];
	char	*line;
	int		rrv;

	line = NULL;
	ft_memset(buff, 0, 1024);
	rrv = read(fd, buff, 1023);
	while (rrv)
	{
		line = ft_strjoin(line, buff);
		ft_memset(buff, 0, 1024);
		rrv = read(fd, buff, 1023);
	}
	return (line);
}
