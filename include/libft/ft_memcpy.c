/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 01:13:51 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/02 01:13:51 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int 	i;
	char	*dust2;
	char	*mirage;

	dust2 = dest;
	mirage = (char *)src;
	i = 0;
	while (size > i)
	{
		dust2[i] = mirage[i];
		i++;
	}
	return (dust2);
}
