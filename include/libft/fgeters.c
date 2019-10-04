#include "../include/volt.h"

void	eof_buff()
{
	int		chr;

	chr = 0;
	while (chr != '\n' && chr != EOF)
		chr = getchar();
}

int		fgeters(char *str, int len)
{
	char	*pos_out;

	pos_out = ft_strnew(1);
	if (fgets(str, len, stdin) != NULL)
	{
		pos_out = ft_strchr(str, '\n');
		if (pos_out != NULL)
			*pos_out = '\0';
		else
			eof_buff();
		return (1);
	}
	else
	{
		eof_buff();
		return (0);
	}
}
