/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 01:02:06 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 01:02:06 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = (*f)(s[i]);
		i++;
	}
	return (dest);
}
