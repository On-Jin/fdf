/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:34:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 19:10:15 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Try with e->size to put map in [H:W]
** if can't = recur(size--)
** if can = rerturn 1
*/

#include "../includes/fdf.h"

static int	try_center(t_env *e, int tempx, int tempy)
{
	if (tempx > WIDTH || tempy > HEIGHT)
	{
		e->it_y = HEIGHT / 2;
		e->div += 1;
		center(e);
		return (0);
	}
	return (1);
}

int			center(t_env *e)
{
	int y;
	int x;
	int tempx;
	int tempy;

	tempy = 0;
	tempx = 0;
	y = 0;
	x = 0;
	e->size = HEIGHT / e->div;
	while (y < e->len_y - 1)
	{
		x = 0;
		while (x < e->len_x - 1)
		{
			tempx = ((x - y) * e->size) + WIDTH / 2;
			tempy = (y + x) * e->size / 2 + e->it_y +
					(e->size / 2 * 0.82 * e->map[y][x]);
			if (try_center(e, tempx, tempy) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
