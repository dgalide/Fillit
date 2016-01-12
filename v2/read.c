/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:45:03 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/12 18:46:40 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int				ft_neighbor(char **piece, int column, int line)
{
	int			l;

	l = 0;
	if (piece[column][line + 1] && piece[column][line + 1] == '#')
		l++;	
	if (piece[column][line - 1] && piece[column][line - 1] == '#')
		l++;
	if (piece[column + 1][line] && piece[column + 1][line] == '#')
		l++;
	if (piece[column - 1][line] && piece[column - 1][line] == '#')
		l++;
	printf("%d\n", l);
	return (l);
}

int				check_line(char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != '.' || line[i] != '#')
			return (0);
		if (line[4] != '\n')
			return (0);
		if (line[i] == '.' || line[i] == '#')
			j++;
		i++;
	}
	printf("%d\n", j);
	if (j != 4)
		return (0);
	else
		return (1);
}

int				check_validity(char **piece)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		printf("%s\n", piece[i]);
		if (check_line(piece[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (piece[i][j])
	{
		if (piece[i][j] == '#')
			k += ft_neighbor(piece, i, j);
		if (piece[i][j] == '\n')
		{
			i++;
			j = 0;
		}
		j++;
	}
	if (k == 6 || k == 8)
		return (1);
	else
		return (0);
}

char		**buff_to_tab(char *buff)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		tab[i] = ft_strsub(buff, j, 4);
		i++;
		j += 5;
	}
	return (tab);
}

int			main(int argc, char **argv)
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
