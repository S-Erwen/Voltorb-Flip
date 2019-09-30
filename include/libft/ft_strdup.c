/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:02:01 by Erwen             #+#    #+#             */
/*   Updated: 2019/08/31 16:02:01 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int 	i;
	int		u;
	char 	*dupage;

	u = 0;
	i = 0;
	while (s[i])
		i++;
	if (!(dupage = (char *)malloc(sizeof(char) * i + 1 )))
		return (NULL);
	i = 0;
	while (s[i])
		dupage[u++] = s[i++];
	dupage[++u] = '\0';

	return (dupage);
}