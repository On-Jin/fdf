/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:12:05 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:41:43 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		while (big[i + count] == little[count])
		{
			count++;
			if (count == ft_strlen(little))
			{
				if (i + count <= i + len)
					return ((char*)big + i);
				else
					return (NULL);
			}
		}
		len--;
		count = 0;
		i++;
	}
	return (NULL);
}
