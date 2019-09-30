/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:53:25 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 15:53:25 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_str_twolen(char const *s1, char const *s2)
{
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	len1 += len2;
	return (len1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int 	size;
	int 	i;
	int 	y;
	char	*str_joined;

	size = ft_str_twolen(s1, s2);
	i = 0;
	y = 0;
	if (!(str_joined = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	while (s1[i])
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		str_joined[i] = s2[y];
		i++;
		y++;
	}
	str_joined[i] = '\0';
	return (str_joined);
}
