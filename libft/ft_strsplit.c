/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:58:26 by ntoniolo          #+#    #+#             */
/*   Updated: 2016/11/22 12:40:48 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static	int	count_word(char *str, char c)
{
	int i;
	int mot;

	mot = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c || mot == 0)
		{
			mot++;
			while (str[i] == c)
				i++;
			if (str[i] == '\0')
				mot--;
		}
		else
			i++;
	}
	return (mot);
}

static	int	ft_wordlen(char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		b;
	int		tab;
	char	**str;

	tab = 0;
	if (s == NULL)
		return (NULL);
	i = 0;
	b = count_word((char*)s, c);
	str = (char**)malloc(sizeof(*str) * b + 1);
	if (str == NULL)
		return (NULL);
	while (b)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		str[tab] = ft_strsub((char*)&s[i], 0, ft_wordlen((char*)&s[i], c));
		i = i + ft_wordlen((char*)&s[i], c);
		tab++;
		b--;
	}
	str[tab] = 0;
	return (str);
}
