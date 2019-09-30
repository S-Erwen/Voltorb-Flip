/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:13:13 by Erwen             #+#    #+#             */
/*   Updated: 2019/08/31 21:13:13 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned int		i;

	i = 0;
	while ((str1[i] == str2[i]) && ((str1[i] && str2[i]) != '\0'))
	{
		if (size == 0)
			return (0);
		i++;
		size--;
	}
	if (size == 0)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
