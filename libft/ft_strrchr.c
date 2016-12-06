/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:58:57 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/08 18:09:50 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = NULL;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			p = (char*)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	else
		return (p);
}
