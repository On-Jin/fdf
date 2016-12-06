/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:06:05 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/08 18:07:11 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t t;

	i = 0;
	t = 0;
	while (dest[i])
		i++;
	while (src[t] && n)
	{
		dest[i + t] = src[t];
		t++;
		n--;
	}
	dest[i + t] = '\0';
	return (dest);
}
