/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:07:58 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/16 02:07:58 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_outputchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		ft_outputchar(n + '0');
	else if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		ft_outputchar('-');
		ft_putnbr(n);
	}
	else if (n > 0)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_outputchar(n);
}
