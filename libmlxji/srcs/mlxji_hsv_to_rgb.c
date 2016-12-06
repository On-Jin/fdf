/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tls.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:02:51 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 18:09:53 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlxji.h"

/*
** V = Max color;
**
** hue on 360
**
**			      R  |   G  |  B
**				     |	    |
** hue [0-1[ =	V    | Up   | Min
** hue [1-2[ =	Down | Max  | Mi
** hue [2-3[ =	Min  | Max  | Up
** hue [3-4[ =	Min  | Down | Max
** hue [4-5[ =	Up   | Min  | Max
** hue [5-6[ =	Max  | Min  | Down
** hue [6->  =	Max  | min  | Up
*/

static void	h0_to_h3(double h, double v, t_hsv *hsv)
{
	if (h < 1)
	{
		hsv->rf = v;
		hsv->gf = hsv->up;
		hsv->bf = hsv->min;
	}
	else if (h >= 1 && h < 2)
	{
		hsv->rf = hsv->down;
		hsv->gf = v;
		hsv->bf = hsv->min;
	}
	else if (h >= 2 && h < 3)
	{
		hsv->rf = hsv->min;
		hsv->gf = v;
		hsv->bf = hsv->up;
	}
}

static void	h3_to_h6(double h, double v, t_hsv *hsv)
{
	if (h >= 3 && h < 4)
	{
		hsv->rf = hsv->min;
		hsv->gf = hsv->down;
		hsv->bf = v;
	}
	else if (h >= 4 && h < 5)
	{
		hsv->rf = hsv->up;
		hsv->gf = hsv->min;
		hsv->bf = v;
	}
	else if (h >= 5 && h < 6)
	{
		hsv->rf = v;
		hsv->gf = hsv->min;
		hsv->bf = hsv->down;
	}
}

int			mlxji_hsv_to_rgb(t_px *px, float h, float s, float v)
{
	t_hsv	hsv;

	h = h * 3.14 / 180;
	hsv.i = (int)h;
	hsv.f = h - hsv.i;
	hsv.min = v * (1 - s);
	hsv.down = v * (1 - hsv.f * s);
	hsv.up = v * (1 - (1 - hsv.f) * s);
	if (h >= 0 && h < 3)
		h0_to_h3(h, v, &hsv);
	else if (h >= 3 && h < 6)
		h3_to_h6(h, v, &hsv);
	else if (h > 6)
	{
		hsv.rf = v;
		hsv.gf = hsv.min;
		hsv.bf = hsv.up;
	}
	px->r = hsv.rf * 255;
	px->g = hsv.gf * 255;
	px->b = hsv.bf * 255;
	return (0);
}
