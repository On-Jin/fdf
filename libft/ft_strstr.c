/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:03:30 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:41:31 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int size;
	int count;

	size = ft_strlen(little);
	i = 0;
	count = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		while (big[i + count] == little[count])
		{
			count++;
			if (count == size)
				return ((char*)big + i);
		}
		count = 0;
		i++;
	}
	return (NULL);
}
