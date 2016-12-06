/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:43:04 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/03 16:13:57 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"

int		key_event_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode)
		e->key[keycode] = 1;
	if (keycode == 82)
		init_env(e);
	if (keycode == 76)
		e->choice = e->choice == 1 ? 0 : 1;
	if (keycode == 18)
		e->color = 1;
	if (keycode == 19)
		e->color = 5;
	if (keycode == 20)
		e->color = 4;
	if (keycode == 21)
		e->color = 2;
	if (keycode == 23)
		e->color = 3;
	return (0);
}

int		key_event_take_off(int keycode, t_env *e)
{
	if (keycode)
		e->key[keycode] = 0;
	return (0);
}
