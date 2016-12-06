/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:35:03 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 19:12:04 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libmlxji/includes/mlxji.h"
#include "mlx.h"

int			init_env(t_env *e)
{
	int i;

	i = -1;
	e->div = e->len_y - 1;
	e->it_y = HEIGHT / 2;
	e->degre = 0;
	e->color = 1;
	e->incli = 2;
	e->exalt = 1;
	e->move_y = 0;
	e->move_x = 0;
	e->choice = 0;
	e->size = HEIGHT / e->div;
	while (e->key[i++])
		e->key[i] = 0;
	e->hue = 0;
	e->saturation = 1;
	e->value = 1;
	return (1);
}

static void	free_env(t_env *e)
{
	int i;

	i = 0;
	while (i < e->len_x)
	{
		free(e->map[i]);
		free(e->coordx[i]);
		free(e->coordy[i]);
		i++;
	}
	free(e->map);
	free(e->coordx);
	free(e->coordy);
}

int			main(int argc, char **argv)
{
	t_env	e;

	if (creat_map(&e, argc, argv) == -1)
		return (0);
	init_env(&e);
	e.mlx = mlx_init();
	e.img = mlxji_new_img(&e, WIDTH, HEIGHT);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "FDF");
	center(&e);
	e.base_size = e.size;
	draw(&e);
	mlx_hook(e.win, 2, 0, &key_event_press, &e);
	mlx_key_hook(e.win, &key_event_take_off, &e);
	mlx_loop_hook(e.mlx, &alteration, &e);
	mlx_loop(e.mlx);
	free_env(&e);
	return (0);
}
