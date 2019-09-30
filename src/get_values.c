/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:25:46 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/13 14:30:58 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		second_half(t_julia *julia)
{
	julia->j6.r = -0.4;
	julia->j6.i = -0.59;
	julia->j7.r = 0.34;
	julia->j7.i = -0.05;
	julia->j8.r = 0.355;
	julia->j8.i = 0.355;
	julia->j9.r = -0.4;
	julia->j9.i = -0.59;
	julia->j10.r = 0.355534;
	julia->j10.i = 0.337292;
}

t_julia		*get_julia(void)
{
	t_julia		*julia;

	if (!(julia = (t_julia *)malloc(sizeof(t_julia))))
		end(ERR_MALLOC);
	julia->index = 1;
	julia->j1.r = -0.624;
	julia->j1.i = 0.435;
	julia->j2.r = 0;
	julia->j2.i = 0.8;
	julia->j3.r = 0.37;
	julia->j3.i = 0.1;
	julia->j4.r = 0.355;
	julia->j4.i = 0.355;
	julia->j5.r = -0.54;
	julia->j5.i = 0.54;
	second_half(julia);
	return (julia);
}

t_val		*get_val(void)
{
	t_val		*val;

	if (!(val = (t_val *)malloc(sizeof(t_val))))
		end(ERR_MALLOC);
	val->maxit = 50;
	val->maxlim = 150;
	val->zoom = 1;
	val->mx = 0;
	val->my = 0;
	val->z.r = -0.624;
	val->z.i = 0.435;
	val->boo = 0;
	val->delta = 0.01;
	val->pressed = 0;
	val->boo2 = 1;
	get_div(val);
	return (val);
}

t_color		*get_color_val(void)
{
	t_color		*color;

	if (!(color = (t_color *)malloc(sizeof(t_color))))
		end(ERR_MALLOC);
	color->amp = 255 / (double)2;
	color->center = 255 - color->amp;
	color->p1 = 0;
	color->p2 = 1;
	color->p3 = 2;
	color->freq = 0.25;
	color->type = 2;
	color->psycho = 0;
	return (color);
}

t_mlx		*get_mlx(int id)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		end(ERR_MALLOC);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W, H, "fractol");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->bpp = 32;
	mlx->s_l = W * 4;
	mlx->endian = 0;
	mlx->id = id;
	mlx->val = get_val();
	mlx->color = get_color_val();
	mlx->julia = get_julia();
	mlx->w2 = W / 2;
	mlx->h2 = H / 2;
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->s_l), &(mlx->endian));
	ft_bzero(mlx->data_addr, W * H * 4);
	return (mlx);
}
