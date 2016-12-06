/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:51:27 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:13:28 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(*dest) * ft_strlen(s) + 1)))
		return (0);
	ft_strcpy(dest, s);
	return (dest);
}
