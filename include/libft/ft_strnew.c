/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 00:28:10 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 00:28:10 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string_malloced;

	if (!(string_malloced = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	return (string_malloced);
}
