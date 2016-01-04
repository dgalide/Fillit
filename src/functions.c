/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:46:34 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/15 17:46:35 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int			ft_map_check_col(t_map *map, int line)
{
	int i;

	i = -1;
	while (++i < map->actualsize)
		if (map->actualcontent[i][line] != '.')
			return (0);
	return (1);
}

int			ft_map_check_line(t_map *map, int col)
{
	int i;

	i = -1;
	while (++i < map->actualsize)
		if (map->actualcontent[col][i] != '.')
			return (0);
	return (1);
}

void		ft_map_del_first_col(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (++y < map->actualsize)
	{
		x = -1;
		while (++x < map->actualsize)
			map->actualcontent[y - 1][x] = map->actualcontent[y][x];
	}
}

void		ft_map_del_first_line(t_map *map)
{
	int y;
	int x;

	x = 0;
	while (++x < map->actualsize)
	{
		y = -1;
		while (++y < map->actualsize)
			map->actualcontent[y][x - 1] = map->actualcontent[y][x];
	}
}

void		ft_scale_map(t_map *map)
{
	if (ft_map_check_line(map, 0) && ft_map_check_col(map, 0))
	{
		ft_map_del_first_col(map);
		ft_map_del_first_line(map);
		map->actualsize--;
	}
	if (ft_map_check_line(map, 0) && ft_map_check_col(map, map->actualsize - 1))
	{
		ft_map_del_first_line(map);
		map->actualsize--;
	}
	if (ft_map_check_line(map, map->actualsize - 1) && ft_map_check_col(map, 0))
	{
		ft_map_del_first_col(map);
		map->actualsize--;
	}
	if (ft_map_check_line(map, map->actualsize - 1) &&
	ft_map_check_col(map, map->actualsize - 1))
		map->actualsize--;
}
