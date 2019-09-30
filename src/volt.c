/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:03:41 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/25 20:03:41 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/volt.h"

int		welcolm()
{
	int 	lng;

	lng = language_selected();
	what_script("42.", lng);
	what_script("1.", lng);
	what_script("7.", lng);
	sleep(2);
	write_ignior(lng);
	return (lng);
}

void	game_volt(int lng)
{
	char	**soluce_map;
	char	**void_map;
	int		i;

	i = 0;
	soluce_map = game_map_with_volt(1);
	void_map = gamevoid_map_with_volt(1);
	while (1)
	{
		sleep(0.4);
		while (void_map[i])
			ft_putstr(void_map[i++]);
		algo_if_is_clear(lng, void_map, soluce_map);
		i = 0;
	}
	i = 0;
	while (soluce_map[i])
		ft_putstr(soluce_map[i++]);
}