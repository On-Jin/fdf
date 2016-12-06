/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:19:50 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 20:02:33 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 100

typedef struct	s_lst
{
	int				fd;
	char			*temp;
	char			*cara;
	struct s_lst	*next;
	struct s_lst	*deb;
}				t_lst;

int				get_next_line(const int fd, char **line);

#endif
