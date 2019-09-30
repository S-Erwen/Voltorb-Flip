#include "../include/volt.h"

char	*chrs_dest(char *s1, int i, int chr)
{
	char	*dest;
	int 	y;
	int 	temp;
	int		count_mall;

	temp = i;
	while (s1[temp] != chr)
		count_mall++;
	if (!(dest = (char *)malloc(sizeof(char) * count_mall + 1)))
		return (NULL);
	y = 0;
	while (s1[i] != chr)
		dest[y++] = s1[i++];
	dest[y] = '\0';
	return (dest);
}

char	*map_strchrstr(char *s1, char *s2, int chr)
{
	int		i;
	int		y;
	int 	x;

	i = 0;
	y = 0;
	x = 0;
	while (s2[x])
		x++;
	if (x == 0)
		return (s1);
	while (s1[i])
	{
		while (s1[i + y] == s2[y])
		{
			if (y == x - 1)
			{
				chrs_dest(s1, i + x + 1, chr);
				return (0);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}

char	*read_map()
{
	int 	fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];
	char	*dest;

	fd = open("/mnt/c/Users/Erwen/Documents/projects/VoltorBataille/src/map/map_base", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open(map) error");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(buf) + 1)))
		return (NULL);
	dest = buf;
	if (close(fd) == -1)
	{
		ft_putstr("close(map) error");
		return (NULL);		
	}
	return (dest);
}

char 	**map_to_tab()
{
	char	**tab;
	char	*map;

	map = read_map();
	tab = ft_strsplit(map, '.');
	return (tab);
}
