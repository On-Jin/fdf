/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxji.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:26:57 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 18:09:30 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXJI_H
# define MLXJI_H

# include "mlx.h"
# include <stdlib.h>
# include <string.h>

typedef struct		s_img
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}					t_img;

typedef struct		s_px
{
	int			r;
	int			g;
	int			b;
}					t_px;

typedef struct		s_hsv
{
	double		rf;
	double		gf;
	double		bf;
	double		i;
	double		min;
	double		f;
	double		down;
	double		up;
}					t_hsv;

typedef struct		s_line
{
	int			dx;
	int			dy;
	int			x;
	int			y;
	int			xincr;
	int			yincr;
	int			cumul;
	int			i;
}					t_line;

typedef struct		s_pxtopx
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}					t_pxtopx;

t_img				*mlxji_new_img(void *mlx, int width, int height);
int					mlxji_clear_img(t_img *img);
void				mlxji_put_pixel(t_img *img, int x, int y, t_px *px);
int					mlxji_hsv_to_rgb(t_px *px, float h, float s, float v);
int					mlxji_draw_line(t_img *img, t_px *px, t_pxtopx *to);
#endif
