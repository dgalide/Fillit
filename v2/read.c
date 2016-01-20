/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:57:02 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/20 04:44:06 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void			ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

char			**buff_to_tab(char *str)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	tab = ft_maketab(5, 4);
	while (i < 4)
	{
		ft_strsub(str, j, 4);
		j += 5;
		i += 1;
	}
	ft_printtab(tab);
	return (tab);
}

int	xchr(char **tab, int c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != NULL)
		{
			if (tab[i][j] == (char)c)
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (ft_error);
}
int	 ychr(char **tab, int c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != NULL)
		{
			if (tab[i][j] == (char)c)
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (ft_error);
}

int				**relativ_pos(char **piece, int **tetrilist, int nb, int total)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = 0;
	j = 0;
	l = 1;
	m = xchr(piece, '#');
	k = ychr(piece, '#');
	while (i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#' && l != 1)
			{
				tetrilist[nb][l] = i - k;
				tetrilist[nb][l + 1] = j - m;
			}
			l++;
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int				ft_read(int const fd)
{
	char 		buff[SIZE_BUFF];
	int			ret;
	char		**tab;
	int			i;
	int			j;
	int			k;

	j = 0;
	ret = read(fd, buff, SIZE_BUFF);
	if (buff[ret + 1] < SIZE_BUFF)
		buff[ret + 1] = '\0';
	else
	{
		ft_putchar('A');
		ft_error();
	}
	if (((ret + 1) % 21) != 0)
	{
		ft_putchar('B');
		ft_error();
	}
	if (check_1(buff, ret) == 0)
	{
		ft_putchar('C');
		ft_error();
	}
	i = ((ret + 1) / 21);
	while (++k < i)
	{
		tab = buff_to_tab(ft_strsub(buff, j, 20));
		if (ft_neighbor(tab) == 0)
		{
			ft_putchar('D');
			ft_error();
		}
		relativ_pos(tab, tetrilist);
		j += 21;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int fd;
	int	i;
	int	**tetrilist;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = ft_read(fd);
		tetrilist = (int **)malloc(sizeof(int *) * i);
		
	}
	return (0);
}
