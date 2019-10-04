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
	int		help;
	char	*chr;
	char	*help_chr;

	if (!(chr = (char *)malloc(sizeof(char) * 4 + 1)))
		return (0);
	lng = language_selected();
	what_script("42.", lng);
	what_script("1.", lng);
	what_script("7.", lng);
	sleep(2);
	help = write_ignior(lng);
	if (help == 777)
	{
		fgets(chr, 2, stdin);
		fgets(chr, 2, stdin);
		if ((chr[0] == 'h') || (chr[0] == 'H'))
		{
			help_chr = i_need_help(lng);
			ft_putstr(help_chr);
			fgets(chr, 6, stdin);
			fgets(chr, 6, stdin);
		}
	}
	return (lng);
}

void	game_volt(int lng, int lvl)
{
	char	**soluce_map;
	char	**void_map;
	int		i;
	int		tt;

	soluce_map = game_map_with_volt(lvl);
	void_map = gamevoid_map_with_volt(lvl);
	tt = game_is_win();
	while (1)
	{
		sleep(0.4);
		i = 0;
		while (void_map[i])
			ft_putstr(void_map[i++]);
		tt = algo_if_is_clear(lng, void_map, soluce_map, tt, lvl);
	}
}