/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volt.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Erwen <dev.sanjaro@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:41:50 by Erwen             #+#    #+#             */
/*   Updated: 2019/09/25 19:41:50 by Erwen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOLT_H
# define VOLT_H

# define BUF_SIZE 4096

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# include "./libft/libft.h"

void	game_volt(int lng);
int		welcolm();

void	ft_putstr(const char *str);
void	ft_putchar(char c);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n);
int		ft_strlen(const char *str);
char	*strchrstr(char *s1, char *s2, int chr);
int		language_selected();
char 	**map_to_tab();
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(char *s1, char *s2);
char	*ft_itoa(int n);

void	what_script(char *nb, int lng);
int		write_ignior(int lng);
char	**game_map_with_volt(int lvl);
char	**gamevoid_map_with_volt(int lvl);
char	get_user_number(int lng, int vtlg);
char	**algo_if_is_clear(int lng, char **void_map, char **soluce_map);
int		nb_to_map(int nb);

# endif
