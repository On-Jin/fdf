/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:14:15 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:12:31 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	left_size;
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	left_size = size;
	while (dest[i] != '\0' && left_size != 0)
	{
		left_size--;
		i++;
	}
	if (left_size == 0)
		return (i + ft_strlen(src));
	while (src[n] != '\0' && left_size != 1)
	{
		dest[i + n] = src[n];
		n++;
		left_size--;
	}
	dest[i + n] = '\0';
	return (i + ft_strlen(src));
}
