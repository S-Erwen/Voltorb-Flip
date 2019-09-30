/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 04:40:32 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/02 04:40:32 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char			*src2;
	char			*dest2;
	unsigned int	i;

	src2 = (char *)src;
	dest2 = dest;
	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	if (src > dest)
	{
		while (size > i)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (size > 0)
		{
			dest2[size - 1] = src2[size - 1];
			size--;
		}
	}
	return (dest);
}