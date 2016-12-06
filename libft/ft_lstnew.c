/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:51:40 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:10:16 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else if (content)
	{
		new->content = (void*)ft_memalloc(sizeof(content_size));
		if (new->content == NULL)
		{
			ft_memdel((void*)&new);
			return (NULL);
		}
		ft_memcpy(new->content, (void*)content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
