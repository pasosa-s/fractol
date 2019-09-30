/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:44:41 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/05 14:43:11 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/controls.h"

void	move(int key, t_mlx *mlx)
{
	double	move;

	move = 0.1 / mlx->val->zoom;
	if (key == KEY_W)
		mlx->val->my -= move;
	else if (key == KEY_A)
		mlx->val->mx -= move;
	else if (key == KEY_S)
		mlx->val->my += move;
	else if (key == KEY_D)
		mlx->val->mx += move;
}

void	phase_et_freq(int key, t_mlx *mlx)
{
	if (key == ARROW_LEFT)
	{
		mlx->color->p1 -= 1;
		mlx->color->p2 -= 1;
		mlx->color->p3 -= 1;
	}
	else if (key == ARROW_RIGHT)
	{
		mlx->color->p1 += 1;
		mlx->color->p2 += 1;
		mlx->color->p3 += 1;
	}
	else if (key == ARROW_UP)
		mlx->color->freq -= 0.01;
	else if (key == ARROW_DOWN)
		mlx->color->freq += 0.01;
}

void	change_rgb(int key, t_mlx *mlx)
{
	if (key == KEY_R)
		mlx->color->p1 += 1;
	else if (key == KEY_G)
		mlx->color->p2 += 1;
	else if (key == KEY_B)
		mlx->color->p3 += 1;
}

void	grey(t_color *color)
{
	color->p1 = 8;
	color->p2 = 8;
	color->p3 = 8;
	color->freq = 0.27;
}

void	change_color_set(t_mlx *mlx)
{
	if (mlx->color->type == 1)
	{
		mlx->color->p1 = 0;
		mlx->color->p2 = 1;
		mlx->color->p3 = 2;
		mlx->color->freq = 0.25;
	}
	else if (mlx->color->type == 2)
		grey(mlx->color);
	else if (mlx->color->type == 3)
	{
		mlx->color->p1 = 1;
		mlx->color->p2 = 2;
		mlx->color->p3 = 3;
		mlx->color->freq = 3.19;
	}
	else if (mlx->color->type == 4)
	{
		mlx->color->p1 = 7;
		mlx->color->p2 = 12;
		mlx->color->p3 = 9;
		mlx->color->freq = 0.5;
	}
	mlx->color->type++;
	mlx->color->type = mlx->color->type == 5 ? 1 : mlx->color->type;
}
