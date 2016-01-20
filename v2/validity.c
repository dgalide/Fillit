/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:43:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/20 16:16:08 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				check_1(char *buff, int ret)
{
	int			j;
	int			k;
	int			l;
	int			i;

	i = ((ret + 1) / 21); // nb tetri;
	j = 4;
	k = 0;
	while (k < i)
	{
		l = 0;
		while (l < 5)
		{
			if (j < (ret - 1) && buff[j] != '\n')
				return (0);
			if (l != 3)
				j += 5;
			else
				j += 1;
			l++;
		}
		k++;
	}
	return (1);
}

int				check_index(int i, int j)
{
	if (i < 0 || i > 3)
		return 0;
	if (j < 0 || j > 3)
		return 0;
	return 1;
}

int				ft_neighbor(char **piece)
{
	int			i;
	int			j;
	int			l;

	l = 0;
	i = 0;
	j = 0;
	ft_putchar('X');
	while (i < 4)
	{
		while (j < 4)
		{
			if (ischar(piece[i][j]) == 0)
				ft_error();
			if (piece[i][j] == '#')
			{
				ft_putchar('#');
				if ((j + 1) < 4 && piece[i][j + 1] == '#')
				{
					ft_putchar('1');
					l++;
				}
				if ((j - 1) > -1 && piece[i][j - 1] == '#')
				{
					ft_putchar('2');
					l++;
				}
				if ((i + 1) < 4 && piece[i + 1][j] == '#')
				{
					ft_putchar('3');
					l++;
				}
				if ((i - 1) > -1 && piece[i - 1][j] == '#')
				{
					ft_putchar('4');
					l++;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	printf("%d\n", l);
	return((l == 6 || l == 8)? 1: 0);
}

/*int			main(int argc, char **argv)
{
	char **tab;
	char buff[22];
	int	fd;

	fd = open(argv[1], O_RDONLY);
	read(fd, buff, 21);
	tab = buff_to_tab(buff);
	printf("%d\n", check_validity(tab));
	return (0);
}
*/