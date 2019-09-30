/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:48:20 by Erwen             #+#    #+#             */
/*   Updated: 2019/08/31 21:48:20 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(char *s1, char *s2)
{
	int		i;
	int		y;
	int 	x;

	i = 0;
	y = 0;
	x = 0;
	while (s2[x])
		x++;
	if (x == 0)
		return (s1);
	while (s1[i])
	{
		while (s1[i + y] == s2[y])
		{
			if (y == x - 1)
				return (s1 + i);
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
