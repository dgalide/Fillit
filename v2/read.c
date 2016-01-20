/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:57:02 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/20 17:07:24 by julio            ###   ########.fr       */
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
	j = 0;
	tab = ft_maketab(5, 4);
	while (i < 4)
	{
		tab[i] = ft_strsub(str, j, 4);
		j += 5;
		i += 1;
	}
	tab[i] = NULL;
	ft_printtab(tab);
	return (tab);
}

int	xchr(char **tab, int c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == (char)c)
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
int	 ychr(char **tab, int c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == (char)c)
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int				*relativ_pos(char **piece)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	*pos;

	i = 0;
	j = 0;
	l = 0;
	k = xchr(piece, '#');
	m = ychr(piece, '#');
	printf("ref(x)= %d && y = %d\n", k, m);
	pos = (int *)malloc(sizeof(int) * 9);
	pos[0] = 0;
	pos[1] = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#' && l < 2)
				l++;
			if (piece[i][j] == '#' && l > 1)
			{
				pos[l] = i - k;
				pos[l + 1] = j - m;
				l += 2;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (pos);
}

void			print_lst(int *lst, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(lst[i]);
		i++;
	}
}

int				ft_read(int const fd, t_map *map)
{
	char 		buff[SIZE_BUFF];
	int			ret;
	char		**tab;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	i = 0;
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
	while (k < i)
	{
		tab = buff_to_tab(ft_strsub(buff, j, 20));
		map->tetrilist = (int **)malloc(sizeof(int *) * i);
		if (ft_neighbor(tab) == 0)
		{
			ft_putchar('D');
			ft_error();
		}
	    map->tetrilist[k] = relativ_pos(tab);
	    map->tetrilist[k][8] = 0;
	    print_lst(map->tetrilist[k], 9);
		j += 21;
		k++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int fd;
	int	i;
	int	**tetrilist;
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = ft_read(fd, map);
		
	}
	return (0);
}
