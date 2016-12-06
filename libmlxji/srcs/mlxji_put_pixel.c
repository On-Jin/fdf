/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxji_put_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:24:46 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/05 12:22:24 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlxji.h"

/*
** 1 Octet per pixel
** 1 B 2 G 3 R
*/

void	mlxji_put_pixel(t_img *img, int x, int y, t_px *px)
{
	img->data[(x * (img->bpp / 8)) + (y * img->size_line)] = px->b;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 1] = px->g;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 2] = px->r;
}
