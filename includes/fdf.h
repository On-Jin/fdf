/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:43:09 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/04 16:58:20 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 2048
# define HEIGHT 1350
# include "../libft/includes/libft.h"
# include "../libmlxji/includes/mlxji.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;

	int			move_x;
	int			move_y;
	float		div;
	float		base_size;
	float		size;
	int			it_y;
	int			key[269];
	float		degre;
	float		exalt;
	float		incli;
	int			choice;

	float		hue;
	float		saturation;
	float		value;

	int			r;
	int			g;
	int			b;
	int			color;
	int			max_z;
	int			past_len_x;
	int			len_x;
	int			len_y;
	int			**map;
	int			**coordx;
	int			**coordy;
}				t_env;

float			iso(t_env *e, float angle_x, float angle_y, int xory);
float			rotation(t_env *e, float x, float y, int xory);
int				creat_map(t_env *e, int argc, char **argv);
int				draw(t_env *e);
int				center(t_env *e);
int				init_env(t_env *e);
void			line_color_fract(t_env *e, t_px *px, t_px *px2, int y1, int y2);
void			color_direction(t_env *e, t_px *px, int z);
int				key_event_press(int keycode, t_env *e);
int				key_event_take_off(int keycode, t_env *e);
int				alteration(t_env *e);

#endif
