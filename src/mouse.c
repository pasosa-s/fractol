/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:21:38 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/13 14:04:40 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/controls.h"

void		moving_mouse(t_coord coord, t_mlx *mlx)
{
	double	move;

	move = 0.1 / mlx->val->zoom;
	if (W / 2 < coord.x)
		mlx->val->mx += move;
	else if (W / 2 > coord.x)
		mlx->val->mx -= move;
	if (H / 2 < coord.y)
		mlx->val->my += move;
	else if (H / 2 > coord.y)
		mlx->val->my -= move;
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_mlx		*mlx;
	t_coord		coord;

	coord.x = x;
	coord.y = y;
	mlx = (t_mlx *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		zoom(button, mlx);
		moving_mouse(coord, mlx);
	}
	else if (button == MOUSE_LEFT_BUTTON)
		mlx->val->pressed = 1;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	create_threads(mlx);
	return (0);
}

int			mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	(void)button;
	mlx = (t_mlx *)param;
	mlx->val->pressed = 0;
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	mlx = (t_mlx *)param;
	if (mlx->id == 2 && mlx->val->boo2)
	{
		mlx->val->z.r = 2 * (x - W / 2) / (0.5 * W);
		mlx->val->z.i = 1.5 * (y - H / 2) / (0.5 * H);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		create_threads(mlx);
	}
	else if (mlx->val->pressed)
	{
		zoom(KEY_E, mlx);
		moving_mouse(coord, mlx);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		create_threads(mlx);
	}
	return (0);
}
