/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:49:11 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 19:06:37 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	color_uni(t_env *e, t_px *px)
{
	mlxji_hsv_to_rgb(px, e->hue, e->saturation, e->value);
}

static void	color_fract2(t_env *e, t_px *px, int z)
{
	float	res;

	px->r = 255;
	px->g = 0;
	px->b = 127;
	res = (float)z / (float)e->max_z;
	if (res > 0.5)
	{
		px->r = 255 * (res - 1);
		px->b = 255 * res;
	}
	else if (res < 0.5 && res > 0)
	{
		px->b = 204 * res;
		px->r = 204 * res * 2;
	}
	else if (res < 0)
	{
		px->r = 2;
		px->g = 20;
		px->b = 240;
	}
}

static void	color_fract(t_env *e, t_px *px, int z)
{
	float	res;

	px->r = 0;
	px->g = 204;
	px->b = 0;
	res = (float)z / (float)e->max_z;
	if (res > 0.5)
	{
		px->g = 204 * (res - 1);
		px->r = 204 * res;
	}
	else if (res < 0.5 && res > 0)
	{
		px->r = 204 * res;
		px->g = 204 * res * 2;
	}
	else if (res < 0)
	{
		px->r = 2;
		px->g = 20;
		px->b = 240;
	}
}

static void	color(t_px *px, int z)
{
	float	res;

	px->r = 0;
	px->g = 204;
	px->b = 0;
	res = z * 5;
	if (res > 0)
	{
		px->r = res - 204;
		if (px->r < 0)
			px->r = 0;
		if (px->r > 204)
			px->r = 204;
		px->g -= res / 3;
		if (px->g < 0)
			px->g = 0;
	}
	else if (res < 0)
	{
		res = -z * 3;
		px->b = 100 + res;
		if (res > 210)
			px->b = 210;
		px->g = 0;
	}
}

void		color_direction(t_env *e, t_px *px, int z)
{
	if (e->color == 1)
		color(px, z);
	if (e->color == 2)
		color_fract(e, px, z);
	if (e->color == 3)
		color_fract2(e, px, z);
	if (e->color == 4 || e->color == 5)
		color_uni(e, px);
}
