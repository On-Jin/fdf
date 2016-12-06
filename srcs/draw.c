/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:04:04 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 18:08:16 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libmlxji/includes/mlxji.h"

static void		draw_line(t_env *e, t_px *px, int x, int y)
{
	t_pxtopx to;

	to.x1 = e->coordx[y][x];
	to.y1 = e->coordy[y][x];
	if (x != 0 && y == 0)
	{
		to.x2 = e->coordx[y][x - 1];
		to.y2 = e->coordy[y][x - 1];
		mlxji_draw_line(e->img, px, &to);
	}
	if (x == 0 && y != 0)
	{
		to.x2 = e->coordx[y - 1][x];
		to.y2 = e->coordy[y - 1][x];
		mlxji_draw_line(e->img, px, &to);
	}
	else if (x != 0 && y != 0)
	{
		to.x2 = e->coordx[y][x - 1];
		to.y2 = e->coordy[y][x - 1];
		mlxji_draw_line(e->img, px, &to);
		to.x2 = e->coordx[y - 1][x];
		to.y2 = e->coordy[y - 1][x];
		mlxji_draw_line(e->img, px, &to);
	}
}

static void		draw_point(t_env *e, t_px *px, int pt_x, int pt_y)
{
	if ((pt_x + e->move_x >= 0 && pt_x + e->move_x <= 2048 - 1) &&
		(pt_y + e->move_y >= 0 && pt_y + e->move_y <= 1350 - 1))
		mlxji_put_pixel(e->img, pt_x + e->move_x, pt_y + e->move_y, px);
}

static int		make(t_env *e, int x, int y)
{
	float		pt_x;
	float		pt_y;
	float		angle_x;
	float		angle_y;
	t_px		px;

	angle_x = 0;
	angle_y = 0;
	pt_x = 0;
	pt_y = 0;
	angle_x = rotation(e, x, y, 1);
	angle_y = rotation(e, x, y, 0);
	pt_x = iso(e, angle_x, angle_y, 1);
	pt_y = iso(e, angle_x, angle_y, 0);
	pt_y = pt_y - ((e->size / 2 * 0.82 * e->map[y][x]) * e->exalt);
	color_direction(e, &px, e->map[y][x]);
	e->coordx[y][x] = pt_x + e->move_x;
	e->coordy[y][x] = pt_y + e->move_y;
	if (e->choice == 0)
		draw_line(e, &px, x, y);
	else
		draw_point(e, &px, pt_x, pt_y);
	return (1);
}

int				draw(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < e->len_y)
	{
		x = 0;
		while (x < e->len_x)
		{
			make(e, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
