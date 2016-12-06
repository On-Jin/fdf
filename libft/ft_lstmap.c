/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:14:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:10:08 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*status;
	t_list	*first;

	first = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new = (*f)(lst);
		if (!(new = ft_lstnew(new->content, new->content_size)))
			return (NULL);
		if (first)
		{
			status->next = new;
			status = new;
		}
		else
		{
			first = new;
			status = new;
		}
		lst = lst->next;
	}
	return (first);
}
