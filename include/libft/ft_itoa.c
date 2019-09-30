/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:35:08 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/18 15:35:08 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		intlen(int n)
{
	int i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n = -n;
		while (n)
		{
			n /= 10;
			i++;
		}
		return (i + 1);
	}
	else if (n > 0)
	{
		while (n)
		{
			n /= 10;
			i++;
		}
		return (i);
	}
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			len;
	long int	l_n;

	l_n = n;
	len = intlen(l_n);
	if (!(nbr = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (l_n < 0)
	{
		nbr[0] = '-';
		l_n = -l_n;
	}
	while (len-- && nbr[len] != '-')
	{
		nbr[len] = l_n % 10 + '0';
		l_n /= 10;
	}
	return (nbr);
}
