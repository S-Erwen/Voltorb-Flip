#include "../include/volt.h"

int		x3;
int		x2;

int		nb_to_map(int nb)
{
	int temp;

	if (nb == 1)
		return (4);
	temp = nb;
	nb = 0;
	nb += 4 * temp;
	return (nb);
}

char	**volt_rand(int lvl)
{
	int		place;
	int 	i;
	int		count;
	char	**map;
	int		ligne;

	srand(time(NULL));
	i = 1;
	map = map_to_tab();
	count = 6 + lvl - 1;
	while (count >= i)
	{
		place = 1;
		ligne = 1;
		while (map[ligne][place] != '#')
		{
			place = (rand() % (25 - 1 + 1)) + 1;
			while (place > 5)
			{
				ligne += 2;
				place -= 5;
			}
			place = nb_to_map(place);
			map[ligne][place] = '#';
		}
		i++;
	}
	return (map);
}

char	**x3_rand(int lvl)
{
	int		place;
	int 	i;
	int		count;

	int 	max;
	int		min;

	char	**map;
	int		ligne;

	srand(time(NULL));
	i = 1;
	map = volt_rand(lvl);
	if (lvl == 1)
	{
		max = 3;
		min = 1;
	}
	else if (lvl == 2 || lvl == 3)
	{
		max = 4;
		min = 1;
	}
	else if (lvl == 4 || lvl == 5)
	{
		max = 5;
		min = 1;
	}
	else if (lvl == 6 || lvl == 7)
	{
		max = 6;
		min = 1;
	}
	else
	{
		max = 7;
		min = 2;
	}
	count = (rand() % (max - min + 1)) + min;
	while (count >= i)
	{
		place = 1;
		ligne = 1;
		while (map[ligne][place] != '#' && map[ligne][place] != '3')
		{
			place = (rand() % (25 - 1 + 1)) + 1;
			while (place > 5)
			{
				ligne += 2;
				place -= 5;
			}
			place = nb_to_map(place);
			map[ligne][place] = '3';
		}
		i++;
	}
	x3 = count;
	return (map);
}

char	**x2_rand(int lvl)
{
	int		place;
	int 	i;
	int		count;

	int 	max;
	int		min;

	char	**map;
	int		ligne;

	srand(time(NULL));
	ligne = 1;
	i = 1;
	map = x3_rand(lvl);
	if (lvl == 1)
	{
		max = 5;
		min = 2;
	}
	else if (lvl == 2)
	{
		max = 6;
		min = 3;
	}
	else if (lvl == 3)
	{
		max = 7;
		min = 2;
	}
	else if (lvl == 4)
	{
		max = 8;
		min = 2;
	}
	else if (lvl == 5)
	{
		max = 9;
		min = 1;
	}
	else if (lvl == 6)
	{
		max = 8;
		min = 0;
	}
	else if (lvl == 7)
	{
		max = 9;
		min = 1;
	}
	else
	{
		max = 8;
		min = 0;
	}
	place = 1;
	place = nb_to_map(place);
	count = (rand() % (max - min + 1)) + min;
	while (count >= i)
	{
		place = 1;
		ligne = 1;
		while (map[ligne][place] != '#' && map[ligne][place] != '#'
				&& map[ligne][place] != '2')
		{
			place = (rand() % (25 - 1 + 1)) + 1;
			while (place > 5)
			{
				ligne += 2;
				place -= 5;
			}
			place = nb_to_map(place);
			map[ligne][place] = '2';
		}
		i++;
	}
	x2 = count;
	return (map);
}

char	**x1_rand(int lvl)
{
	int		place;
	char	**map;
	int		ligne;
	int 	twenty_five;
	int 	z;

	z = 0;
	twenty_five = 25;
	ligne = 1;
	place = 1;
	map = x2_rand(lvl);
	while (twenty_five != 0)
	{
		ligne = 1;
		place = 1 + z;
		while (place > 5)
		{
			ligne += 2;
			place -= 5;
		}
		place = nb_to_map(place);
		if ((map[ligne][place] != '#' && map[ligne][place] != '3'
			&& map[ligne][place] != '2' && map[ligne][place] != '1') && twenty_five != 0)
			map[ligne][place] = '1';
		twenty_five--;
		z++;
	}
	return (map);
}

char	**game_soluce_hz(int lvl)
{
	// map[][30] == #-->' '<-- case volt
	// map[][26] == |'  '-->' '<-- case len
	char	**map;
	int 	volt = 0;
	int 	two = 0;
	int 	three = 0;
	int 	one = 0;

	map = x1_rand(lvl);

	int		place;
	int		ligne;
	int 	twenty_five;
	int 	z;
	char	*past;

	z = 0;
	twenty_five = 25;
	ligne = 1;
	place = 1;
	while (twenty_five != 0)
	{
		place = 1 + z;
		while (place > 5)
			place -= 5;
		place = nb_to_map(place);
		if (twenty_five == 20 || twenty_five == 15
		|| twenty_five == 10 || twenty_five == 5)
		{
			past = ft_itoa(volt);
			if (ft_strlen(past) == 1)
				map[ligne][30] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[ligne][30] = past[0];
				map[ligne][31] = past[1];
			}
			past = ft_itoa(three * 3 + two * 2 + one);
			if (ft_strlen(past) == 1)
				map[ligne][26] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[ligne][26] = past[0];
				map[ligne][27] = past[1];
			}
			ligne += 2;
			volt = 0;
			three = 0;
			two = 0;
			one = 0;
		}
		if (map[ligne][place] == '#')
			volt++;
		if (map[ligne][place] == '3')
			three++;
		if (map[ligne][place] == '2')
			two++;
		if (map[ligne][place] == '1')
			one++;
		twenty_five--;
		if (twenty_five == 0)
		{
			past = ft_itoa(volt);
			if (ft_strlen(past) == 1)
				map[ligne][30] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[ligne][30] = past[0];
				map[ligne][31] = past[1];
			}
			past = ft_itoa(three * 3 + two * 2 + one);
			if (ft_strlen(past) == 1)
				map[ligne][26] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[ligne][26] = past[0];
				map[ligne][27] = past[1];
			}
			ligne += 2;
			volt = 0;
			three = 0;
			two = 0;
			one = 0;
		}
		z++;
	}
	return (map);
}
char	**game_soluce_vt(int lvl)
{
	// map[13][] == #-->' '<-- case volt
	// map[15][] == |'  '-->' '<-- case len
	char	**map;
	int 	volt = 0;
	int 	two = 0;
	int 	three = 0;
	int 	one = 0;

	int 	twenty_five;
	int		place;
	int		ligne;
	char	*past;
	int 	z;

	ligne = 1;
	place = 1;
	z = 0;
	map = game_soluce_hz(lvl);
	twenty_five = 25;
	while (twenty_five != 0)
	{
		place = 1 + z;
		place = nb_to_map(place);
		if (map[ligne][place] == '#')
			volt++;
		if (map[ligne][place] == '3')
			three++;
		if (map[ligne][place] == '2')
			two++;
		if (map[ligne][place] == '1')
			one++;
		twenty_five--;
		if (twenty_five == 20 || twenty_five == 15
		|| twenty_five == 10 || twenty_five == 5)
		{
			past = ft_itoa(volt);
			if (ft_strlen(past) == 1)
				map[15][place] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[15][place] = past[0];
				map[15][place + 1] = past[1];
			}
			past = ft_itoa(three * 3 + two * 2 + one);
			if (ft_strlen(past) == 1)
				map[13][place] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[13][place] = past[0];
				map[13][place + 1] = past[1];
			}
			ligne = -1;
			volt = 0;
			three = 0;
			two = 0;
			one = 0;
			z++;
		}
		if (twenty_five == 0)
		{
			past = ft_itoa(volt);
			if (ft_strlen(past) == 1)
				map[15][place] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[15][place] = past[0];
				map[15][place + 1] = past[1];
			}
			past = ft_itoa(three * 3 + two * 2 + one);
			if (ft_strlen(past) == 1)
				map[13][place] = past[0];
			else if (ft_strlen(past) == 2)
			{
				map[13][place] = past[0];
				map[13][place + 1] = past[1];
			}
			ligne = -1;
			volt = 0;
			three = 0;
			two = 0;
			one = 0;
			z++;
		}
		ligne += 2;
	}
	return (map);
}

char	**game_map_with_volt(int lvl)
{
	char	**map;
	map = game_soluce_vt(lvl);
	return (map);
}

char	**gamevoid_map_with_volt(int lvl)
{
	char	**map;
	int		place;
	int		ligne;
	int 	twenty_five;
	int 	z;

	z = 0;
	twenty_five = 25;
	ligne = 1;
	place = 1;
	map = game_soluce_vt(lvl);
	while (twenty_five != 0)
	{
		ligne = 1;
		place = 1 + z;
		while (place > 5)
		{
			ligne += 2;
			place -= 5;
		}
		place = nb_to_map(place);
		map[ligne][place] = ' ';
		twenty_five--;
		z++;
	}
	return (map);
}

int		game_is_win()
{
	int tt;
	
	tt = x3 + x2;
	return (tt);
}

int		algo_if_is_clear(int lng, char **void_map, char **soluce_map, int tt, int lvl)
{
	int		hz;
	int		vt;
	int		i;

	i = 0;
	if (tt == 0)
	{
		what_script("777.", lng);
		lvl++;
		what_script("997.", lng);
		ft_putstr(ft_itoa(lvl));
		ft_putchar('\n');
		sleep(1.5);
		game_volt(lng, lvl);
	}
	hz = get_user_number(lng, 2);
	vt = get_user_number(lng, 1);
	if (soluce_map[hz][vt] == '#')
	{
		what_script("999.", lng);
		sleep(3);
		while (soluce_map[i])
			ft_putstr(soluce_map[i++]);
		sleep(3);
		lvl = 1;
		what_script("997.", lng);
		ft_putstr(ft_itoa(lvl));
		ft_putchar('\n');
		sleep(1);
		game_volt(lng, lvl);
	}
	if (void_map[hz][vt] != ' ')
	{
		what_script("8.", lng);
		return (algo_if_is_clear(lng, void_map, soluce_map, tt, lvl));
	}
	else if ((soluce_map[hz][vt] == '3') || (soluce_map[hz][vt] == '2'))
	{
		void_map[hz][vt] = soluce_map[hz][vt];
		tt--;
	}
	else if (soluce_map[hz][vt] == '1')
		void_map[hz][vt] = soluce_map[hz][vt];
	return (tt);
}