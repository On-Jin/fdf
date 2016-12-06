/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alteration2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:17:50 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/03 16:30:38 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exalt(t_env *e)
{
	if (e->key[69])
		e->exalt += 0.15;
	if (e->key[78])
		e->exalt -= 0.15;
}

void	incli(t_env *e)
{
	if (e->key[91])
	{
		if (e->incli < 8)
			e->incli += 0.2;
	}
	if (e->key[84])
	{
		if (e->incli > 1)
			e->incli -= 0.2;
	}
}

void	move(t_env *e)
{
	if (e->key[3])
		e->move_x += 5;
	if (e->key[1])
		e->move_x -= 5;
	if (e->key[2])
		e->move_y += 5;
	if (e->key[14])
		e->move_y -= 5;
}

void	degre(t_env *e)
{
	if (e->key[86])
		e->degre += 0.1;
	if (e->key[88])
		e->degre -= 0.1;
}

void	size(t_env *e)
{
	if (e->key[15])
	{
		if (e->size < e->base_size * HEIGHT / 8)
			e->size *= 1.1;
	}
	if (e->key[17])
		e->size *= 0.9;
}
