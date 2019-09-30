/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:00:43 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/26 17:11:55 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		get_color(t_color *color, int maxit, int i, t_complex z)
{
	t_rgb	colors;
	double	index;

	if (i == maxit)
		return (0x000000);
	index = i + 1 + ((log(2) / ABS(z.r * z.r + z.i * z.i))) / log(2);
	colors.r = sin(color->freq * index + color->p1) * 127.5 + 127.5;
	colors.g = sin(color->freq * index + color->p2) * 127.5 + 127.5;
	colors.b = sin(color->freq * index + color->p3) * 127.5 + 127.5;
	return (rgb_to_int(colors.r, colors.g, colors.b));
}

void	put_pixel(t_mlx *mlx, t_coord p, int n, t_complex z)
{
	int		color;
	int		i;

	i = 0;
	color = get_color(mlx->color, mlx->val->maxit, n, z);
	if ((p.x >= 0 && p.x <= W) && (p.y >= 0 && p.y <= H))
	{
		i = ((p.x * (mlx->bpp / 8)) + (p.y * mlx->s_l));
		mlx->data_addr[i] = color;
		mlx->data_addr[++i] = color >> 8;
		mlx->data_addr[++i] = color >> 16;
	}
}
