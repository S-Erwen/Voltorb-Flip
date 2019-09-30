/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 00:14:16 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/13 00:14:16 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*void_malloced;

	if (!(void_malloced = (void *)malloc(sizeof(void) * size + 1)))
		return (0);
	return (void_malloced);
}