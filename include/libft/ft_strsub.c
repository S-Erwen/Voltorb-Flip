/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 01:43:21 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 01:43:21 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string_malloced;
	unsigned int 	i;
	unsigned int	max_len;

	if (!(string_malloced = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	max_len = 0;
	while (s[max_len])
		max_len++;
	if (max_len < start)
		return (0);
	while (i < len && s[start])
	{
		string_malloced[i] = (char)s[start];
		start++;
		i++;
	}
	string_malloced[i] = '\0';
	return (string_malloced);
}
