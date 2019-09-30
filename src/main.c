/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:20:43 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/06 12:24:28 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		valid(char *av)
{
	int		i;

	i = ft_atoi(av);
	if (i >= 1 && i <= 8)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	char	*s;

	if (ac != 2)
		end(ERR_USAGE);
	if (!valid(av[1]))
	{
		s = "\n    -- Usage --"
			"\n\n1-Mandelbrot\n2-Julia\n3-Burning Ship\n4-tricorn"
			"\n5-Manowar\n6-Newton\n7-heart\n8-Mandelcube"
			"\n\n    -----------\n";
		end(s);
	}
	mlx = get_mlx(ft_atoi(av[1]));
	create_threads(mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
