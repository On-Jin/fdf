/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:09:52 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:40:18 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(&s[start]) < len)
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (s[start] && len)
	{
		str[i] = s[start];
		start++;
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
