/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:05:02 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/25 20:05:02 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/volt.h"

int		language_selected()
{
	int		lng;
	
	lng = 0;
	ft_putstr("== Select Language ==\n1. English\n2. Francais\n");
	while (lng <= '0' || lng >= '3')
	{
		lng = getchar();
		if (!(lng >= '0' || lng <= '3'))
			ft_putstr("Between 1 & 2 !\n");
	}
	if (lng == '1')
		return (1);
	else
		return (2);
}

char	*read_script(int lng)
{
	int 	fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];
	char	*dest;

	if (lng == 1)
		fd = open("/mnt/c/Users/Erwen/Documents/projects/Voltorb-Flip/src/language/eng_script_language", O_RDONLY);
	else
		fd = open("/mnt/c/Users/Erwen/Documents/projects/Voltorb-Flip/src/language/fr_script_language", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open(script) error");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(buf) + 1)))
		return (NULL);
	dest = buf;
	if (close(fd) == -1)
	{
		ft_putstr("close(script) error");
		return (NULL);		
	}
	return (dest);
}

void	what_script(char *nb, int lng)
{
	char 	*script;

	script = read_script(lng);
	strchrstr(script, nb, '$');
}

int		write_ignior(int lng)
{
	int 	fd2;
	int 	rett;
	char	buff[BUF_SIZE + 1];

	fd2 = open("/mnt/c/Users/Erwen/Documents/projects/Voltorb-Flip/src/language/.ignore", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd2 == -1)
		ft_putstr("open(ignore) error");
	rett = read(fd2, buff, BUF_SIZE);
	buff[rett] = '\0';
	ft_putchar_fd('0', fd2);
	if (ft_strlen(buff) <= 3)
	{
		what_script("2.", lng);
		what_script("3.", lng);
	}
	if (close(fd2) == -1)
		ft_putstr("close(ignore) error");
	if (ft_strlen(buff) <= 3)
		return (777);
	return (0);
}

char	get_user_number(int lng, int vtlg)
{
	char 	*nb;
	int 	i;
	int		temp;
	char	*help_chr;

	nb = 0;
	i = 0;
	nb = ft_strnew(4);
	if (write_ignior(lng) != 777)
		what_script("13.", lng);
	if (vtlg == 1)
		what_script("5.", lng);
	else
		what_script("6.", lng);
	fgeters(nb, 2);
	sleep(0.3);
	while (!(nb[0] > 0 && nb[0] < 6))
	{
		fgeters(nb, 2);
		if (!(nb[0] == ('h' - '0') || nb[0] == ('H' - '0'))
			&& (nb[0] > '0' && nb[0] < '6'))
			nb[1] = getchar();
		sleep(0.2);
		nb[0] -= '0';
		if (nb[0] == ('h' - '0') || nb[0] == ('H' - '0'))
		{
			help_chr = i_need_help(lng);
			ft_putstr(help_chr);
			what_script("9.", lng);
			fgeters(nb, 1);
			get_user_number(lng, vtlg);
		}
		else if (!(nb[0] > 0 && nb[0] < 6))
			what_script("4.", lng);
	}
	if (vtlg == 1)
		nb[0] = nb_to_map(nb[0]);
	else if (vtlg == 2)
	{
		temp = -1;
		while (nb[0] > i)
		{
			temp += 2;
			i++;
		}
		nb[0] = temp;
	}
	return (nb[0]);
}

char	*i_need_help(int lng)
{
	int 	fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];
	char	*dest;

	if (lng == 1)
		fd = open("/mnt/c/Users/Erwen/Documents/projects/Voltorb-Flip/src/map/help_eng", O_RDONLY);
	else
		fd = open("/mnt/c/Users/Erwen/Documents/projects/Voltorb-Flip/src/map/help_fr", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open(help) error");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(buf) + 1)))
		return (NULL);
	dest = buf;
	if (close(fd) == -1)
	{
		ft_putstr("close(help) error");
		return (NULL);		
	}
	return (dest);
}
