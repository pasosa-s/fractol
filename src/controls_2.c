/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:26:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/13 14:35:51 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/controls.h"

void	change(int id, t_mlx *mlx)
{
	mlx->id = id;
	mlx->val->zoom = 1;
	mlx->val->mx = 0;
	mlx->val->my = 0;
	mlx->val->z.r = (mlx->id == 2) ? -0.624 : 0;
	mlx->val->z.i = (mlx->id == 2) ? 0.435 : 0;
	mlx->val->maxit = 50;
	mlx->val->maxlim = 150;
	mlx->val->pressed = 0;
	mlx->val->boo2 = 1;
	get_div(mlx->val);
}

void	change_fractals(int key, t_mlx *mlx)
{
	if (key == NUM_1 && mlx->id != 1)
		change(1, mlx);
	else if (key == NUM_2 && mlx->id != 2)
		change(2, mlx);
	else if (key == NUM_3 && mlx->id != 3)
		change(3, mlx);
	else if (key == NUM_4 && mlx->id != 4)
		change(4, mlx);
	else if (key == NUM_5 && mlx->id != 5)
		change(5, mlx);
	else if (key == NUM_6 && mlx->id != 6)
		change(6, mlx);
	else if (key == NUM_7 && mlx->id != 7)
		change(7, mlx);
	else if (key == NUM_8 && mlx->id != 8)
		change(8, mlx);
	else if (key == NUM_9 && mlx->id != 9)
		change(9, mlx);
}

void	change_julia(int key, t_mlx *mlx)
{
	double		delta;

	delta = mlx->val->delta;
	if (key == PAD_NUM_2)
		mlx->val->z.i -= delta;
	else if (key == PAD_NUM_8)
		mlx->val->z.i += delta;
	else if (key == PAD_NUM_4)
		mlx->val->z.r -= delta;
	else if (key == PAD_NUM_6)
		mlx->val->z.r += delta;
	if (ABS(mlx->val->z.r) > 2 || ABS(mlx->val->z.i) > 2)
	{
		mlx->val->z.r = 0;
		mlx->val->z.i = 0;
	}
}

void	get_z(int index, t_mlx *mlx)
{
	if (index == 1)
		mlx->val->z = mlx->julia->j1;
	else if (index == 2)
		mlx->val->z = mlx->julia->j2;
	else if (index == 3)
		mlx->val->z = mlx->julia->j3;
	else if (index == 4)
		mlx->val->z = mlx->julia->j4;
	else if (index == 5)
		mlx->val->z = mlx->julia->j5;
	else if (index == 6)
		mlx->val->z = mlx->julia->j6;
	else if (index == 7)
		mlx->val->z = mlx->julia->j7;
	else if (index == 8)
		mlx->val->z = mlx->julia->j8;
	else if (index == 9)
		mlx->val->z = mlx->julia->j9;
	else if (index == 10)
		mlx->val->z = mlx->julia->j10;
}

void	nice_julias(int key, t_mlx *mlx)
{
	if (key == PAD_NUM_7 || key == PAD_NUM_9)
	{
		if (key == PAD_NUM_7)
			mlx->julia->index--;
		else if (key == PAD_NUM_9)
			mlx->julia->index++;
		if (mlx->julia->index == 11)
			mlx->julia->index = 1;
		else if (mlx->julia->index == 0 || mlx->julia->index == -1)
			mlx->julia->index = 10;
		get_z(mlx->julia->index, mlx);
	}
	else if (key == PAD_NUM_5)
	{
		mlx->val->z = (t_complex) {.r = 0, .i = 0};
		mlx->julia->index = 0;
	}
}
