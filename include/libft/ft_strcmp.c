/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:54:20 by Erwen             #+#    #+#             */
/*   Updated: 2019/08/30 23:54:20 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	unsigned int		i;

	i = 0;
	while ((str1[i] == str2[i]) && ((str1[i] && str2[i]) != '\0'))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}