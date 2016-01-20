/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:43:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/20 15:43:09 by julio            ###   ########.fr       */
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
	if (i < 0 || j < 0)
		return 0;
	if (i > 3 || j > 3)
		return 0;
	return (1);
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
			{
				ft_putchar('Z');
				return (0);
			}
			if (check_index(i , (j + 1)) == 1 && piece[i][j + 1] == '#')
				l++;
			if (check_index(i, (j - 1)) == 1 && piece[i][j - 1] == '#')
				l++;
			if (check_index((i + 1), j) == 1 && piece[i + 1][j] == '#')
				l++;
			if (check_index((i - 1), j) == 1 && piece[i - 1][j] == '#')
				l++;
			j++;
		}
		i++;
		j = 0;
	}
	printf("%d\n", i);
	return((j == 6 || j == 8)? 1: 0);
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