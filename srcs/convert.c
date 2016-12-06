/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:13:57 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/03 15:15:08 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

float	iso(t_env *e, float angle_x, float angle_y, int xory)
{
	float pt;

	pt = 0;
	if (xory == 1)
		pt = (angle_x - angle_y) * e->size + (WIDTH / 2);
	else if (xory == 0)
		pt = (angle_y + angle_x) * e->size / e->incli + e->it_y;
	return (pt);
}

float	rotation(t_env *e, float x, float y, int xory)
{
	float	pt;
	float	radian;

	radian = e->degre * 3.141 * 180;
	pt = 0;
	if (xory == 1)
		pt = (x - e->len_x / 2) * cos(radian) -
			(y - e->len_y / 2) * sin(radian);
	else if (xory == 0)
		pt = (y - e->len_y / 2) * cos(radian) +
			(x - e->len_x / 2) * sin(radian);
	return (pt);
}
