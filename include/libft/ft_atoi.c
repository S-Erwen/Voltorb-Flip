/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:12:26 by Erwen             #+#    #+#             */
/*   Updated: 2019/08/31 13:12:26 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_atoi(const char *nptr)
{
	int		nb;
	int 	i;
	int 	count;

	i = 0;
	count = 114;
	nb = 0;
	while (nptr[i])
	{
		while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' 
			|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
			i++;
		if (nptr[i] == '+')
			i++;
		else if (nptr[i] == '-')
		{
			i++;
			count++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nb *= 10;
			nb += nptr[i++] - 48;
		}
		if (count == 115 && nb != 0)
			return (-nb);
		else
			return (nb);
	}
	return (0);
}