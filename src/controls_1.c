/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 08:42:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/13 14:36:08 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/controls.h"

void	zoom(int key, t_mlx *mlx)
{
	if (key == KEY_E || key == MOUSE_SCROLL_DOWN)
	{
		mlx->val->zoom *= 1.1;
		if (mlx->val->zoom > 10 && mlx->val->maxit < mlx->val->maxlim)
			mlx->val->maxit += 1;
	}
	else if (key == KEY_Q || key == MOUSE_SCROLL_UP)
	{
		mlx->val->zoom *= 0.9;
		if (mlx->val->zoom > 10 && mlx->val->zoom < 7779
				&& mlx->val->maxit <= mlx->val->maxlim)
			mlx->val->maxit -= 1;
	}
	if (mlx->val->zoom < 0.1)
		mlx->val->zoom = 0.1;
	if (mlx->color->psycho)
		phase_et_freq(ARROW_RIGHT, mlx);
	get_div(mlx->val);
}

void	reset(t_mlx *mlx)
{
	mlx->val->zoom = 1;
	mlx->val->mx = 0;
	mlx->val->my = 0;
	mlx->val->z.r = (mlx->id == 2) ? -0.624 : 0;
	mlx->val->z.i = (mlx->id == 2) ? 0.435 : 0;
	mlx->val->maxit = 50;
	mlx->val->maxlim = 150;
	mlx->val->pressed = 0;
	mlx->color->p1 = 0;
	mlx->color->p2 = 1;
	mlx->color->p3 = 2;
	mlx->color->freq = 0.25;
	mlx->color->type = 2;
	mlx->color->psycho = 0;
	mlx->julia->index = 1;
	mlx->val->boo2 = 1;
	get_div(mlx->val);
}

void	maxit(int key, t_mlx *mlx)
{
	if (key == V_LEFT)
		mlx->val->maxit--;
	else if (key == V_RIGHT)
		mlx->val->maxit++;
	if (mlx->val->maxit < 1)
		mlx->val->maxit = 1;
	else if (mlx->val->maxit > 256)
		mlx->val->maxit = 256;
}

void	more_keys(int key, t_mlx *mlx)
{
	if (key == KEY_P)
		mlx->color->psycho = (mlx->color->psycho) ? 0 : 1;
	else if (key == KEY_R || key == KEY_G || key == KEY_B)
		change_rgb(key, mlx);
	else if (key == PAD_ADD)
		mlx->val->maxit += 50;
	else if (key == PAD_RES)
		mlx->val->maxit -= 50;
	else if (key == KEY_Z)
		mlx->val->boo2 = (mlx->val->boo2) ? 0 : 1;
	else if (key == KEY_T)
		mlx->val->maxlim = (mlx->val->maxlim == 150) ? 300 : 150;
	else if (mlx->id == 2 && (key == PAD_NUM_5 ||
				key == PAD_NUM_7 || key == PAD_NUM_9))
		nice_julias(key, mlx);
	else if (mlx->id == 2 && (key == PAD_NUM_1 || key == PAD_NUM_3))
		div_delta(key, mlx);
	else if (mlx->id == 2 && (key == PAD_NUM_2 || key == PAD_NUM_8 ||
				key == PAD_NUM_4 || key == PAD_NUM_6))
		change_julia(key, mlx);
	else if (key == NUM_1 || key == NUM_2 || key == NUM_3 || key == NUM_4 ||
			key == NUM_5 || key == NUM_6 || key == NUM_7 || key == NUM_8)
		change_fractals(key, mlx);
	mlx->val->maxit = (mlx->val->maxit < 0) ? 0 : mlx->val->maxit;
	mlx->val->maxit = (mlx->val->maxit > 1000) ? 1000 : mlx->val->maxit;
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == KEY_ESC)
		free_mlx(mlx);
	else if (key == KEY_M)
		mlx->val->boo = mlx->val->boo ? 0 : 1;
	else if (key == KEY_W || key == KEY_A ||
			key == KEY_S || key == KEY_D)
		move(key, mlx);
	else if (key == KEY_Q || key == KEY_E)
		zoom(key, mlx);
	else if (key == KEY_C)
		change_color_set(mlx);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT ||
			key == ARROW_UP || key == ARROW_DOWN)
		phase_et_freq(key, mlx);
	else if (key == V_LEFT || key == V_RIGHT)
		maxit(key, mlx);
	else if (key == KEY_SPACE)
		reset(mlx);
	more_keys(key, mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	create_threads(mlx);
	return (0);
}
