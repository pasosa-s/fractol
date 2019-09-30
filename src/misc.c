/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:27:36 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/10 15:35:55 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/controls.h"

void	free_mlx(t_mlx *mlx)
{
	free(mlx->julia);
	mlx->julia = NULL;
	free(mlx->val);
	mlx->val = NULL;
	free(mlx->color);
	mlx->color = NULL;
	free(mlx);
	mlx = NULL;
	exit(0);
}

void	div_delta(int key, t_mlx *mlx)
{
	if (key == PAD_NUM_1)
		mlx->val->delta *= 10;
	else if (key == PAD_NUM_3)
		mlx->val->delta /= 10;
	if (mlx->val->delta == 1)
		mlx->val->delta = 0.1;
	if (mlx->val->delta == 0.00001)
		mlx->val->delta = 0.0001;
}

char	*get_string(double delta)
{
	char	*s;

	if (delta == 0.1)
		s = "0.1";
	else if (delta == 0.01)
		s = "0.01";
	else if (delta == 0.001)
		s = "0.001";
	else
		s = "0.0001";
	return (s);
}

void	get_div(t_val *val)
{
	val->w_div = (0.5 * val->zoom * W) / 2;
	val->h_div = (0.5 * val->zoom * H) / 1.5;
}
