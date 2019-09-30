/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:04:06 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 17:04:06 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		strs_clen(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (len);
		len++;
		i++;
	}
	return (len);
}

int		strs_ulen(char const *s, char c, int u)
{
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i] == c && s[i + 1] != c)
				u--;
			i++;
		}
		while (u == 0 && s[i])
		{
			len++;
			i++;
			if (s[i] == c)
				return (len);
		}
		i++;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	int 	len;
	int		i;
	int		y;
	int		u;
	char	**strs;
	
	i = 0;
	len = strs_clen(s, c);
	while (s[i] == c && s[i])
		i++;
	if (!(strs = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	if (len == 0 || s[i] == '\0')
		return (strs);
	y = 0;
	u = 0;
	if (!(strs[u] = (char *)malloc(sizeof(char) * strs_ulen(s, c, 0) + 1)))
		return (0);
	while (len > 0)
	{
		if (s[i] == c)
		{
			strs[u][y] = '\0';
			u++;
			y = 0;
			if (!(strs[u] = (char *)malloc(sizeof(char) * strs_ulen(s, c, u) + 1)))
				return (0);
			while (s[i] == c && s[i])
				i++;
		}
		strs[u][y++] = s[i++];
		len--;
	}
	strs[u][y] = '\0';
	return (strs);
}
