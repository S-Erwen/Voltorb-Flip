/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:48:49 by Erwen             #+#    #+#             */
/*   Updated: 2019/08/31 14:48:49 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	unsigned int i;

	i = 0;
	while (src[i] && size > i)
	{
		dest[i] = src[i];
		i++;
	}
	while (size > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}