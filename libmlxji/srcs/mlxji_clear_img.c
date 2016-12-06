/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxji_clear_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:28:23 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 23:43:41 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlxji.h"

int		mlxji_clear_img(t_img *img)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img->data[(x * (img->bpp / 8)) + (y * img->size_line)] = 0;
			img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 1] = 0;
			img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 2] = 0;
			x++;
		}
		y++;
	}
	return (1);
}
