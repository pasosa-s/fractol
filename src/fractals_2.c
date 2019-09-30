/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:38:29 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/09 12:37:31 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	cube(double a)
{
	return (a * a * a);
}

void	mandelcube(t_mlx *mlx, t_coord p)
{
	t_complex	c;
	t_complex	z;
	t_complex	old;
	int			i;

	i = 0;
	c.r = (p.x - mlx->w2) / mlx->val->w_div + mlx->val->mx;
	c.i = (p.y - mlx->h2) / mlx->val->h_div + mlx->val->my;
	z = (t_complex) {.r = 0, .i = 0};
	while ((z.r * z.r + z.i * z.i < 4) && i < mlx->val->maxit)
	{
		old.r = z.r;
		old.i = z.i;
		z.r = cube(old.r) - 3 * old.r * old.i * old.i + c.r;
		z.i = 3 * old.r * old.r * old.i - cube(old.i) + c.i;
		i++;
	}
	put_pixel(mlx, p, i, z);
}
