/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:59:21 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/12/05 13:14:10 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	*convert_x(t_env *e, char **tab)
{
	int	i;
	int	*nb;
	int	nb_x;

	nb_x = 0;
	nb = 0;
	i = 0;
	while (tab[nb_x])
		nb_x++;
	if (!(nb = (int*)malloc(sizeof(int*) * nb_x)))
		return (0);
	while (tab[i])
	{
		nb[i] = ft_atoi(tab[i]);
		if (nb[i] > e->max_z)
			e->max_z = nb[i];
		i++;
	}
	e->len_x = i;
	if (e->len_x != e->past_len_x && e->past_len_x != 0)
		return (NULL);
	e->past_len_x = e->len_x;
	ft_strdel(tab);
	return (nb);
}

static void	free_tab(char **tab, int len)
{
	int j;

	j = 0;
	while (j < len)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	tab = NULL;
}

static int	creat_map_x(t_env *e, int fd)
{
	int		i;
	char	*line;
	char	**tab;

	if ((!(e->coordx = (int**)malloc(sizeof(int*) * e->len_y))) ||
		(!(e->map = (int**)malloc(sizeof(int*) * e->len_y))) ||
		(!(e->coordy = (int**)malloc(sizeof(int*) * e->len_y))))
		return (0);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		e->map[i] = convert_x(e, tab);
		if (e->map[i] == NULL)
			return (0);
		free_tab(tab, e->len_x);
		if ((!(e->coordx[i] = (int*)malloc(sizeof(int*) * e->len_x))) ||
			(!(e->coordy[i] = (int*)malloc(sizeof(int*) * e->len_x))))
			return (0);
		if (line)
			free(line);
		i++;
	}
	return (1);
}

static int	creat_map_y(t_env *e, char **argv)
{
	int		fd;
	char	*line;
	char	buff[1];

	fd = open(argv[1], O_RDONLY);
	if (!fd || read(fd, &buff, 0) == -1)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		e->len_y += 1;
		if (line)
			free(line);
	}
	e->div = e->len_y;
	close(fd);
	return (1);
}

int			creat_map(t_env *e, int argc, char **argv)
{
	int fd;

	e->max_z = 0;
	e->past_len_x = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Erreur : nombres d'arguments != 2\n", 2);
		return (-1);
	}
	if (creat_map_y(e, argv) == 0)
	{
		ft_putstr_fd("Erreur : Fichier non valide\n", 2);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	if (creat_map_x(e, fd) - 1)
	{
		ft_putstr_fd("Erreur : Fichier non valide\n", 2);
		return (-1);
	}
	close(fd);
	return (1);
}
