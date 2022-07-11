/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:19:09 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/01 08:34:17 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_var	m;

	ft_memset(&m, 0, sizeof(m));
	if (ac != 2)
		ft_error(&m, 1);
	m.init = mlx_init();
	if (!av[1])
		ft_error(&m, 2);
	ft_parsing(&m, av[1]);
	m.win.lenght = 800;
	m.win.height = 600;
	m.ref_coef = 0.3;
	m.ref_num = 0;
	ft_vec_init(&m);
	m.win.ptr = mlx_new_window(m.init, m.win.lenght, m.win.height, "miniRT");
	ft_image_render(&m);
	mlx_hook(m.win.ptr, 17, 0, ft_please_stop, &m);
	mlx_hook(m.win.ptr, 2, 0, ft_imput_first, &m);
	mlx_loop(m.init);
	ft_exit(&m, 0);
}
