/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:21:02 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/13 14:30:28 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "stdio.h"
# include "pthread.h"

# define W 800
# define H 600
# define THREADS 64

# define ABS(value) ((value < 0) ? (value * (-1)) : value)
# define SQR(value) value * value;
# define CUBE(value) value * value * value;

# define ERR_MALLOC "error trying to allocate memory"
# define ERR_USAGE "Usage: ./fractol <number> [ 1 to 8 ]"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_values
{
	t_complex	p;
	t_complex	pre;
	t_complex	cur;
	t_coord		c;
}				t_values;

typedef struct	s_val
{
	double		zoom;
	double		mx;
	double		my;
	int			maxit;
	int			maxlim;
	int			boo;
	int			pressed;
	t_complex	z;
	double		delta;
	double		w_div;
	double		h_div;
	int			boo2;
}				t_val;

typedef struct	s_color
{
	double		freq;
	double		amp;
	double		center;
	int			p1;
	int			p2;
	int			p3;
	int			type;
	int			psycho;
}				t_color;

typedef struct	s_julia
{
	int			index;
	t_complex	j1;
	t_complex	j2;
	t_complex	j3;
	t_complex	j4;
	t_complex	j5;
	t_complex	j6;
	t_complex	j7;
	t_complex	j8;
	t_complex	j9;
	t_complex	j10;
}				t_julia;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		s_l;
	int		endian;
	int		id;
	t_color	*color;
	t_val	*val;
	t_julia	*julia;
	int		w2;
	int		h2;
}				t_mlx;

typedef struct	s_thread
{
	pthread_t	t;
	int			n;
	t_mlx		*mlx;
}				t_thread;

void			end(char *message);
t_mlx			*get_mlx(int id);

void			create_threads(t_mlx *mlx);
void			set_div(t_val *val);
void			get_div(t_val *val);

void			nice_julias(int key, t_mlx *mlx);
void			change_julia(int key, t_mlx *mlx);

void			burning_ship(t_mlx *mlx, t_coord p);
void			tricorn(t_mlx *mlx, t_coord p);
void			manowar(t_mlx *mlx, t_coord p);
void			newton(t_mlx *mlx, t_coord p);
void			heart(t_mlx *mlx, t_coord p);
void			mandelcube(t_mlx *mlx, t_coord p);

void			reset(t_mlx *mlx);
void			move(int key, t_mlx *mlx);
void			zoom(int key, t_mlx *mlx);
int				key_press(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			change_fractals(int key, t_mlx *mlx);

void			div_delta(int key, t_mlx *mlx);
void			free_mlx(t_mlx *mlx);
void			put_pixel(t_mlx *mlx, t_coord p, int i, t_complex z);

void			text_screen(t_mlx *mlx);
void			menu(t_mlx *mlx);
void			text_menu_left(t_mlx *big_mlx);
void			text_menu_right(t_mlx *big_mlx);

int				per(int n, int per);
int				rgb_to_int(int r, int g, int b);
char			*get_string(double delta);
void			phase_et_freq(int key, t_mlx *mlx);
void			change_rgb(int key, t_mlx *mlx);
void			change_color_set(t_mlx *mlx);

#endif
