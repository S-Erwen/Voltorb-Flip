/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:53:07 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/01 13:53:07 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t size)
{
	unsigned int		i;
	unsigned int		y;
	unsigned int 		x;

	i = 0;
	y = 0;
	x = 0;
	while (s2[x])
		x++;
	if (x == 0)
		return (s1);
	while (s1[i] && (i < size))
	{
		while ((s1[i + y] == s2[y]) && (i + y < size))
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