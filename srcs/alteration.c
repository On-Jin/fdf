/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alteration.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:53:15 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 23:42:56 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/alteration.h"

static void	color_choice(t_env *e)
{
	if (e->key[257] && e->key[6])
		e->hue += 5;
	if (e->key[6] && e->key[257] == 0)
		e->hue -= 5;
	e->key[7] > 0 && e->key[257] == 0 && e->saturation < 1 ?
		e->saturation += 0.05 : 0;
	e->key[7] > 0 && e->key[257] > 0 && e->saturation > 0 ?
		e->saturation -= 0.05 : 0;
	e->key[8] > 0 && e->key[257] == 0 && e->value < 1 ?
		e->value += 0.05 : 0;
	e->key[8] > 0 && e->key[257] > 0 && e->value > 0 ?
		e->value -= 0.05 : 0;
}

int			alteration(t_env *e)
{
	mlxji_clear_img(e->img);
	move(e);
	degre(e);
	size(e);
	exalt(e);
	incli(e);
	draw(e);
	color_choice(e);
	if (e->color == 5)
		e->hue += 1;
	if (e->hue >= 360)
		e->hue = 0;
	if (e->hue < 0)
		e->hue = 360;
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	return (1);
}
