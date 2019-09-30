#include "libft.h"

void	chr_suite(char *s1, int i, int chr)
{
	while (s1[i] != chr)
		ft_putchar(s1[i++]);
	ft_putchar('\n');
}

char	*strchrstr(char *s1, char *s2, int chr)
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
				chr_suite(s1, i + x + 1, chr);
				return (0);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
