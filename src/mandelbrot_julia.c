/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:16:36 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/28 18:05:15 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_julia(t_mlx *mlx, t_coord p)
{
	t_complex	c;
	t_complex	old;
	t_complex	new;
	int			i;

	i = 0;
	c.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	c.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	if (mlx->id == 1)
		new = (t_complex) {.r = 0, .i = 0};
	else if (mlx->id == 2)
	{
		new = c;
		c = mlx->val->z;
	}
	while ((new.r * new.r + new.i * new.i < 4) && i < mlx->val->maxit)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	put_pixel(mlx, p, i, new);
}

void	calling(t_mlx *mlx, t_coord p)
{
	if (mlx->id == 1 || mlx->id == 2)
		mandelbrot_julia(mlx, p);
	else if (mlx->id == 3)
		burning_ship(mlx, p);
	else if (mlx->id == 4)
		tricorn(mlx, p);
	else if (mlx->id == 5)
		manowar(mlx, p);
	else if (mlx->id == 6)
		newton(mlx, p);
	else if (mlx->id == 7)
		heart(mlx, p);
	else if (mlx->id == 8)
		mandelcube(mlx, p);
}

void	*draw(void *vt)
{
	t_coord		p;
	t_thread	*t;
	int			y_max;

	t = (t_thread *)vt;
	p.y = H * t->n / THREADS;
	y_max = H * (t->n + 1) / THREADS;
	while (p.y < y_max)
	{
		p.x = 0;
		while (p.x < W)
		{
			calling(t->mlx, p);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

void	free_t(t_thread *t)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		t[i].mlx = NULL;
		i++;
	}
	free(t);
	t = NULL;
}

void	create_threads(t_mlx *mlx)
{
	t_thread	*t;
	int			i;

	t = (t_thread *)malloc(sizeof(t_thread) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		t[i].n = i;
		t[i].mlx = mlx;
		pthread_create(&t[i].t, NULL, draw, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i].t, NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	text_screen(mlx);
	free_t(t);
	mlx->val->boo ? menu(mlx) : 0;
}
