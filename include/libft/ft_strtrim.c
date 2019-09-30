/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:17:56 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 16:17:56 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		str_len_without_white(char const *s)
{
	int		len;
	int		len_temp;
	int		i;

	i = 0;
	len = 0;
	len_temp = 0;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		len++;
		i++;
	}
	len_temp = len;
	i--;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		len--;
		if (len == 0 || i == 0)
			return (len_temp);
	}
	return (len);
}

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		y;
	char	*cpys;

	len = str_len_without_white((char *)s);
	if (!(cpys = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	y = 0;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len > 0)
	{
		cpys[y] = s[i];
		y++;
		i++;
		len--;
	}
	cpys[y] = '\0';
	return (cpys);
}
