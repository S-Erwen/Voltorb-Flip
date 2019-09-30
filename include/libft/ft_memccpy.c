/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 01:39:01 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/02 01:39:01 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned int 	i;
	char			*dust2;
	char			*mirage;

	dust2 = (char *)dest;
	mirage = (char *)src;
	i = 0;
	while (i < size)
	{
		dust2[i] = mirage[i];
		if (dust2[i] == c)
			return (dust2 + i + 1);
		i++;
	}
	return (NULL);
}