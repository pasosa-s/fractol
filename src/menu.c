/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:02:00 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/26 16:50:32 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/controls.h"
#include "../inc/colors.h"

void	get_name(char **s1, int id)
{
	if (id == 1)
		*s1 = "Mandelbrot";
	else if (id == 2)
		*s1 = "Julia";
	else if (id == 3)
		*s1 = "Burning Ship";
	else if (id == 4)
		*s1 = "Tricorn";
	else if (id == 5)
		*s1 = "Flower";
	else if (id == 6)
		*s1 = "Newton";
	else if (id == 7)
		*s1 = "Heart";
	else if (id == 8)
		*s1 = "Mandelcube";
}

void	text_screen(t_mlx *mlx)
{
	void	*m_ptr;
	void	*win;
	char	*s1;
	char	*s2;

	m_ptr = mlx->mlx_ptr;
	win = mlx->win_ptr;
	get_name(&s1, mlx->id);
	s2 = ft_itoa(mlx->val->maxit);
	mlx_string_put(m_ptr, win, 10, H - 40, WHITE, s1);
	mlx_string_put(m_ptr, win, 10, H - 20, WHITE, s2);
	mlx_string_put(m_ptr, win, 635, H - 25, WHITE, "menu = [ M ]");
	if (mlx->id == 2)
	{
		s1 = get_string(mlx->val->delta);
		if (mlx->julia->index > 0)
		{
			free(s2);
			s2 = ft_itoa(mlx->julia->index);
			mlx_string_put(m_ptr, win, 75, H - 40, WHITE, s2);
		}
		mlx_string_put(m_ptr, win, 635, H - 42, WHITE, "movement");
		mlx_string_put(m_ptr, win, 735, H - 42, WHITE, s1);
	}
	free(s2);
}

void	text_menu_left(t_mlx *big_mlx)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = big_mlx->mlx_ptr;
	win = big_mlx->win_ptr;
	x = per(W, 10);
	y = per(H, 10);
	mlx_string_put(mlx, win, x += 10, y += 10, M,
			"[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] = fractals");
	mlx_string_put(mlx, win, x, y += 50, M, "[ Q ] [ W ] [ E ] ");
	mlx_string_put(mlx, win, x, y += 30, M, "[ A ] [ S ] [ D ]");
	mlx_string_put(mlx, win, x += 200, y -= 30, M, "Q E = zoom in / out");
	mlx_string_put(mlx, win, x, y += 30, M, "W A S D = move");
	mlx_string_put(mlx, win, x -= 200, y += 50, M, "[ < ] [ > ]");
	mlx_string_put(mlx, win, x += 200, y, M,
			"Change max iteration (also [+][-] = +/- 50)");
	mlx_string_put(mlx, win, x -= 200, y += 50, M, "[ R ] [ G ] [ B ]");
	mlx_string_put(mlx, win, x += 200, y, M, "change RED, GREEN or BLUE");
	mlx_string_put(mlx, win, x -= 200, y += 30, M, "[ C ] [ P ]");
	mlx_string_put(mlx, win, x += 200, y, M, "change color set  //  Psycho");
	text_menu_right(big_mlx);
}

void	text_menu_right(t_mlx *big_mlx)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = big_mlx->mlx_ptr;
	win = big_mlx->win_ptr;
	x = per(W, 10);
	y = per(H, 55);
	mlx_string_put(mlx, win, x += 10, y += 10, M, "      [ ^ ]");
	mlx_string_put(mlx, win, x, y += 30, M, "[ < ] [ v ] [ > ]");
	mlx_string_put(mlx, win, x += 200, y -= 30, M, "^ v = change Freq");
	mlx_string_put(mlx, win, x, y += 30, M, "< > = change RGB");
	mlx_string_put(mlx, win, x -= 200, y += 50, M, "[ 7 ] [ 8 ] [ 9 ]");
	mlx_string_put(mlx, win, x, y += 30, M, "[ 4 ] [ 5 ] [ 6 ]");
	mlx_string_put(mlx, win, x, y += 30, M, "[ 1 ] [ 2 ] [ 3 ]");
	mlx_string_put(mlx, win, x += 200, y -= 60, M,
			"7 9 = prev / next saved Julia");
	mlx_string_put(mlx, win, x, y += 30, M, "4 6 8 2 = change Julia");
	mlx_string_put(mlx, win, x, y += 30, M, "1 3 = change delta move");
	mlx_string_put(mlx, win, x, y += 30, M,
			"5 = reset Julia (.re = 0, .im = 0)");
}

void	menu(t_mlx *mlx)
{
	int		*image;
	int		i;
	int		pw;
	int		ph;

	image = (int *)mlx->data_addr;
	i = 0;
	pw = per(W, 10);
	ph = per(H, 10);
	while (i < W * H)
	{
		if (i % W > pw && i % W < W - pw && i > W * ph && i < W * (H - ph))
			image[i] = GG;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	text_menu_left(mlx);
}
