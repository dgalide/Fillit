/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:46:56 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/15 17:46:57 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		ft_clean_map(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < map->bestsize)
	{
		x = -1;
		while (++x < map->bestsize)
			map->actualcontent[y][x] = '.';
	}
	map->actualsize = 0;
}

void		ft_clean_lst(t_piece *lst)
{
	while (lst)
	{
		lst->used = 0;
		lst = lst->next;
	}
}

int			ft_count_bestsize(t_piece *lst)
{
	int xmax;
	int ymax;

	xmax = 0;
	ymax = 0;
	while (lst)
	{
		xmax += lst->x_size;
		ymax += lst->y_size;
		lst = lst->next;
	}
	if (xmax > ymax)
		return (xmax);
	else
		return (ymax);
}

t_map		*ft_init_map(t_map *map, t_piece *lst)
{
	int i;

	i = -1;
	map = (t_map*)malloc(sizeof(t_map));
	map->bestsize = ft_count_bestsize(lst);
	map->bestcontent = (char **)malloc(sizeof(char*) * map->bestsize);
	map->actualcontent = (char **)malloc(sizeof(char*) * map->bestsize);
	map->lst = (t_piece*)malloc(sizeof(t_piece));
	map->lst = lst;
	map->actualsize = 0;
	while (++i < map->bestsize)
	{
		map->bestcontent[i] = (char *)malloc(sizeof(char) * map->bestsize);
		map->actualcontent[i] = (char *)malloc(sizeof(char) * map->bestsize);
	}
	return (map);
}
