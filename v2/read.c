/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:57:02 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/20 19:47:08 by julio            ###   ########.fr       */
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
	if (ft_neighbor(tab) == 0)
		ft_error();
	return (tab);
}

void	xychr(char **tab, int *x, int *y, int c)
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
			{
				*x = i;
				*y = j;
				i = 4;
				j = 4;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void				relativ_pos(char **piece, t_map *map, int nb)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	m;

	i = -1;
	j = 0;
	l = 0;
	xychr(piece, &m, &k, '#');
	while (++i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#' && l < 2)
				l++;
			if (piece[i][j] == '#' && l > 1)
			{
				map->tetrilist[nb][l] = i - k;
				map->tetrilist[nb][l + 1] = j - m;
				l += 2;
			}
			j++;
		}
		j = 0;
	}
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

int				**malloc_list(int nb_tetri)
{
	int			**tetrilist;
	int			i;

	i = 0;
	tetrilist = (int **)malloc(sizeof(int *) * nb_tetri);
	while (i < nb_tetri)
	{
		tetrilist[i] = (int *)malloc(sizeof(int) * 9);
		ft_bzero(tetrilist[i], 9);
		i++;
	}
	return (tetrilist);
}

int				ft_read(int const fd, t_map *map)
{
	char 		buff[SIZE_BUFF];
	char		**tmp;
	int			ret;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	ret = read(fd, buff, SIZE_BUFF);
	check(buff, ret);
	i = ((ret + 1) / 21);
	map->tetrilist = malloc_list(i);
	while (k < i)
	{
		tmp = buff_to_tab(ft_strsub(buff, j, 20));
	    relativ_pos(tmp, map, k);
		j += 21;
		k++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int fd;
	int	i;
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = ft_read(fd, map);
		
	}
	return (0);
}
