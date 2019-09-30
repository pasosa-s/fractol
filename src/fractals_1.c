/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:13:32 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/09 12:37:33 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		burning_ship(t_mlx *mlx, t_coord p)
{
	int			i;
	t_complex	c;
	t_complex	z;
	double		xtemp;

	i = 0;
	c.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	c.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i < 4) && i < mlx->val->maxit)
	{
		xtemp = z.r * z.r - z.i * z.i + c.r;
		z.i = ABS(2 * z.r * z.i) + c.i;
		z.r = ABS(xtemp);
		i++;
	}
	put_pixel(mlx, p, i, z);
}

void		tricorn(t_mlx *mlx, t_coord p)
{
	int			i;
	t_complex	c;
	t_complex	z;
	double		xtemp;

	i = 0;
	c.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	c.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i < 4) && i < mlx->val->maxit)
	{
		xtemp = z.r * z.r - z.i * z.i + c.r;
		z.i = -2 * z.r * z.i + c.i;
		z.r = xtemp;
		i++;
	}
	put_pixel(mlx, p, i, z);
}

void		manowar(t_mlx *mlx, t_coord p)
{
	int			i;
	t_complex	c;
	t_complex	old;
	t_complex	new;

	i = 0;
	c.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	c.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	new = (t_complex) {.r = 0, .i = 0};
	while ((new.r * new.r + new.i * new.i < 4) && i < mlx->val->maxit)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + old.r + c.r;
		new.i = 2 * old.r * old.i + old.i + c.i;
		i++;
	}
	put_pixel(mlx, p, i, new);
}

void		newton(t_mlx *mlx, t_coord p)
{
	t_complex	z;
	t_complex	old;
	double		tmp;
	int			i;

	i = 0;
	tmp = 1.0;
	z.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	z.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	while (tmp > 0.000001 && i < mlx->val->maxit)
	{
		old.r = z.r;
		old.i = z.i;
		tmp = ((z.r * z.r + z.i * z.i) * (z.r * z.r + z.i * z.i));
		z.r = (2 * z.r * tmp + z.r * z.r - z.i * z.i) / (3.0 * tmp);
		z.i = (2 * z.i * (tmp - old.r)) / (3.0 * tmp);
		tmp = (z.r - old.r) * (z.r - old.r) + (z.i - old.i) * (z.i - old.i);
		i++;
	}
	put_pixel(mlx, p, i, z);
}

void		heart(t_mlx *mlx, t_coord p)
{
	int			i;
	t_complex	c;
	t_complex	z;
	double		xtemp;

	i = 0;
	c.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	c.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i < 4) && i < mlx->val->maxit)
	{
		xtemp = z.r * z.r - z.i * z.i + c.r;
		z.i = ABS(z.r) * z.i * 2.0 + c.i;
		z.r = xtemp;
		i++;
	}
	put_pixel(mlx, p, i, z);
}
