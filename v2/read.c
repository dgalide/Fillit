/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:57:02 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/19 20:35:45 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void			ft_error(void)
{
	ft_strendl("error");
	exit(EXIT_FAILURE);
}

char			**buff_to_tab(char *str)
{
	int			i;
	char		**tab;

	i = 0;
	tab = ft_maketab(5, 4)

}

int				ft_read(int const fd)
{
	char 		buff[SIZE_BUFF];
	int			ret;
	int			i;
	int			j;

	j = 0;
	ret = read(fd, buff, SIZE_BUFF);
	if (buff[ret + 1])
		buff[ret + 1] = '\0';
	else
		ft_error();
	if (((ret + 1) % 21) != 0)
		ft_error();
	if (check_1(buff, ret) == 0)
		ft_error();
	i = ((ret + 1) / 21);
	while (i != 0)
	{
		tab = buff_to_tab(ft_strsub(buff, j, 21));
		if (check_neighbor(tab) == 0)
			ft_error();
		//relativ_pos(tab, map);
		i--;
		j += 21;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_read(fd);
	}
	return (0);
}
